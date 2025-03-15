cmake_minimum_required(VERSION 3.10)
project(check_kit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(check_kit main.cpp
    include/document.h src/document.cpp
    include/kit.h src/kit.cpp
    include/kitchecker.h src/kitchecker.cpp)
