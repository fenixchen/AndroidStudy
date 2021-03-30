cmake_minimum_required(VERSION 3.0)

project(SpWp)

add_executable(spwp
    spwp.cpp 
)

target_link_libraries(spwp binder)
