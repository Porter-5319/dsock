cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(APP_NAME "client")
project(${APP_NAME})

#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../lib)

find_package(Qt5Core)

include_directories(${CMAKE_SOURCE_DIR}/lib/src)
link_directories(${CMAKE_SOURCE_DIR}/lib)
link_libraries("dsock")

file(GLOB_RECURSE SRC_CPP ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
file(GLOB_RECURSE SRC_H ${CMAKE_CURRENT_LIST_DIR}/*.h)
add_executable(${APP_NAME} ${SRC_CPP} ${SRC_H})
#add_library(${APP_NAME} ${SRC_CPP} ${SRC_H}) # 生成静态库

target_link_libraries(${APP_NAME} Qt5::Core)
