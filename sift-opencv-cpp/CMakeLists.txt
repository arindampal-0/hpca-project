cmake_minimum_required( VERSION 3.12 )
project( OpenCVSetup )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( main main.cpp )
target_link_libraries( main ${OpenCV_LIBS} )