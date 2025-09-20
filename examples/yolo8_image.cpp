#include <string>
#include <vector>

#include <glog/logging.h>
#include <wanderary/apps/yolo.h>
#include <wanderary/utils/convertor.h>
#include <wanderary/utils/yaml_utils.h>
#include <wanderary/visualization/draw_boxes.h>

using YOLOv8 = wdr::apps::YOLOv8;
using Box2DDrawer = wdr::vis::Box2DDrawer;

Box2DDrawer CreateDrawer(const std::string &names_path) {
  const auto names = wdr::LoadJson(names_path);
  const int class_num = names.size();
  std::vector<std::string> class_names(class_num);
  for (const auto &item : names.items())
    class_names[std::stoi(item.key())] = item.value();
  return Box2DDrawer(class_num, class_names);
}

int main(int argc, char **argv) {
  // 数据加载
  const std::string cfgpath = "configs/stat_yolov8_time_cfg.yaml";
  const std::string imgpath = "data/000000460347.jpg";
  const std::string typespath = "data/coco_type_names.json";
  const std::string savepath = ".cache/000000460347_res.jpg";

  // 加载配置/图像/可视化
  const auto cfg = wdr::LoadYaml<wdr::json>(cfgpath);
  const auto img = cv::imread(imgpath);
  Box2DDrawer drawer = CreateDrawer(typespath);

  // Yolo初始化
  YOLOv8 yolov8("yolov8", cfg, 1);

  // 推理
  const auto rois =
      wdr::ImageCropROIs(img.size(), cv::Size(-1, -1), cv::Size(-1, -1), false);
  const auto box2ds = yolov8.run(img, rois, nullptr);

  // 可视化
  cv::Mat vis;
  img.copyTo(vis);
  drawer.draw(box2ds, &vis);
  cv::imwrite(savepath, vis);
  LOG(INFO) << "Save visualization to " << savepath;
  return 0;
}
