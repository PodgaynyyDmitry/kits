cmake_minimum_required(VERSION 3.10)
project(kits)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(kits main.cpp
    include/document.h src/document.cpp
    include/kit.h src/kit.cpp
    include/kitchecker.h src/kitchecker.cpp)
