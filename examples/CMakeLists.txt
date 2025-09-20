

file (GLOB HEADERS "*.h")
file (GLOB SOURCES "[^_]*.cpp")


set(BIN yolo8-image)
add_executable(${BIN} yolo8_image.cpp)
target_link_libraries(${BIN} wdr::wdr_visualization wdr::wdr_apps)
