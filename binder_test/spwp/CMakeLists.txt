cmake_minimum_required(VERSION 3.0)

project(SpWp)

add_executable(spwp
    sp_wp_main.cpp
    light_ref_base.cpp
    sp_test.cpp
    wp_test.cpp
    cycle_ref_test.cpp
)

target_link_libraries(spwp binder)
