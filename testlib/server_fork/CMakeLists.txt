cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(APP_NAME "server_fork")
project(${APP_NAME})

include_directories(${CMAKE_SOURCE_DIR}/lib/src/socket)
include_directories(${CMAKE_SOURCE_DIR}/lib/src/fork)
include_directories(${CMAKE_SOURCE_DIR}/lib/src/signal)

find_package(Qt5Core)

include_directories(${CMAKE_SOURCE_DIR}/lib/src)
link_directories(${CMAKE_SOURCE_DIR}/lib)
link_libraries("dsock")

file(GLOB_RECURSE SRC_CPP ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
file(GLOB_RECURSE SRC_H ${CMAKE_CURRENT_LIST_DIR}/*.h)
add_executable(${APP_NAME} ${SRC_CPP} ${SRC_H})

target_link_libraries(${APP_NAME} Qt5::Core)
