import json

import cv2
import yaml
from wanderary import Box2DDrawer, ImageCropROIs, YOLOv8


def create_drawer(class_num, names_path):
    class_names = [""] * 80
    with open(names_path, "r") as f:
        names = json.load(f)
        for i, name in enumerate(names):
            class_names[int(i)] = name
    return Box2DDrawer(80, class_names)


if __name__ == '__main__':
    cfgpath = "configs/stat_yolov8_time_cfg.yaml"
    imgpath = "data/000000460347.jpg"
    typespath = "data/coco_type_names.json"
    savepath = ".cache/000000460347_pyres.jpg"

    # 加载配置/图像/可视化
    with open(cfgpath, 'r') as f:
        cfg = yaml.safe_load(f)
    img = cv2.imread(imgpath)
    drawer = create_drawer(80, typespath)

    # 初始化
    yolo = YOLOv8("yolov8", cfg, 1)

    # 推理
    rois = ImageCropROIs(img.shape[1::-1], (-1, -1), (-1, -1), False)
    bbox2ds = yolo.run(img, rois)

    # 可视化
    vis = drawer.draw(bbox2ds, img)
    cv2.imwrite(savepath, vis)
