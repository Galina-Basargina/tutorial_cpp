# tutorial_cpp

упражнения с C++

## Сборка проекта с помощью CMake

```bash
rm -rf build
mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

При этом обычно простейший файл CMakeLists.txt выглядит так:

```cmake
cmake_minimum_required(VERSION 3.5)

project(tutorial_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(application_name main.cpp file1.cpp file2.cpp)
```