#Déclaration du projet
project(camera_test)
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)

#set(CUDA_TOOLKIT_ROOT_DIR "/usr/locaal/cuda")

find_package(CUDA REQUIRED)

#link_directories(/usr/local/lib)

#set(OpenCV_DIR "/usr/local/lib/OpenCV/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)


cuda_add_executable(camera_test ../main_TK1.cpp)

cuda_add_executable(camera_test ../my_lib.h)
cuda_add_executable(camera_test ../my_lib.cpp)

target_link_libraries(camera_test Qt5::Widgets)
target_link_libraries(camera_test Qt5::Core)
target_link_libraries(camera_test opencv_core opencv_highgui opencv_imgproc)# opencv_imgcodecs opencv_video opencv_videoio)
