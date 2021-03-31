cmake_minimum_required(VERSION 3.0)

project(binder)

set(CMAKE_C_FLAGS "-O0 -g3 -Wno-deprecated-declarations")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_library(ProtobufShared protobuf)

add_subdirectory(calc)
add_subdirectory(spwp)
add_subdirectory(binder_ctrl)
add_subdirectory(libs)
add_subdirectory(test_service)
add_subdirectory(async_service)
add_subdirectory(login_service)
add_subdirectory(clipboard_service)
add_subdirectory(servicemanager)
