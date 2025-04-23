# SIFT OpenCV C++
## Resources
- https://stackoverflow.com/questions/30622304/opencv-3-blobdetection-the-function-feature-is-not-implemented-in-detectand

## Setup (Ubuntu)
Make sure to install OpenCV library
```shell
sudo apt update
sudo apt install libopencv-dev
```

Also install C++ compiler and build tool
```shell
sudo apt update
sudo apt install build-essential cmake
```

Build using CMake
```shell
cmake -B build
cmake --build build
```

Run the built program
```shell
build/main
```
