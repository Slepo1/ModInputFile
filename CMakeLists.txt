cmake_minimum_required(VERSION 3.5)

project(ModFile LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(ModFile
  main.cpp
  ModFile.cpp
  ModFile.h
  MyTimer.cpp
  MyTimer.h
)
target_link_libraries(ModFile Qt5::Core)
