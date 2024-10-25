cmake_minimum_required(VERSION 3.5)

project(tutorial_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tutorial_cpp
    main.cpp
    vector.cpp
    thread.cpp)

install(TARGETS tutorial_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

add_executable(laba2 laba2.cpp)
add_executable(laba3 laba3.cpp)
add_executable(laba4 laba4.cpp)
add_executable(laba5 laba5_main.cpp laba5_class.cpp)
add_executable(laba6 laba6.cpp)
add_executable(laba6_thread laba6_thread.cpp)
add_executable(laba7 laba7.cpp)
add_executable(laba8 laba8.cpp)
