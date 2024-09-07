cmake_minimum_required(VERSION 3.5)

project(tutorial_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tutorial_cpp main.cpp vector.cpp)

install(TARGETS tutorial_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
