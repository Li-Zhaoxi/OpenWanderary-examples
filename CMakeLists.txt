cmake_minimum_required(VERSION 3.5)

project(wanderary-examples LANGUAGES CXX)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug)
ENDIF()
MESSAGE(STATUS "Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)


find_package(wdr REQUIRED)
# find_package(OpenCV 4 REQUIRED)
# find_package(Boost 1.71.0 REQUIRED)
# find_package(Eigen3 REQUIRED)
# find_package(GTest REQUIRED)
# find_package(pybind11 REQUIRED)
# find_package(pybind11_json REQUIRED)
# find_package(TBB REQUIRED)
# find_package(yaml-cpp REQUIRED)
# find_package(indicators REQUIRED)


# include("${CMAKE_SOURCE_DIR}/cmake/pack_3rdparty.cmake")

# include_directories(
#   ${EIGEN3_INCLUDE_DIRS}
#   ${OpenCV_INCLUDE_DIRS}
#   ${Boost_INCLUDE_DIRS}
#   ${CMAKE_SOURCE_DIR}
# )

# message(STATUS "OPENCV Lib path: ${OpenCV_LIBRARY_DIRS}")
# link_directories(
#   ${OpenCV_LIBRARY_DIRS}
#   ${Boost_LIBRARY_DIRS}
# )

# link_directories(
#   /usr/hobot/lib/
# )


add_subdirectory(examples)
