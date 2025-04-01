cmake_minimum_required(VERSION 3.10)
project(Fsast_Socket)

#添加头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#添加源文件
add_library(Fsast_Socket src/Fsast_Socket.cpp)
