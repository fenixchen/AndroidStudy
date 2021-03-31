cmake_minimum_required(VERSION 3.5)

project(libbinder)

file(GLOB_RECURSE BINDER_SRCS ${CMAKE_CURRENT_LIST_DIR}/binder/*.cpp)

file(GLOB_RECURSE CUTILS_SRCS ${CMAKE_CURRENT_LIST_DIR}/cutils/*.c)

file(GLOB_RECURSE UTILS_SRCS ${CMAKE_CURRENT_LIST_DIR}/utils/*.cpp)


add_library(binder SHARED
    ${CUTILS_SRCS}
    ${UTILS_SRCS}
    ${BINDER_SRCS}
    )

target_compile_definitions(binder PUBLIC
    HAVE_PTHREADS 
    HAVE_SYS_UIO_H 
    HAVE_ENDIAN_H 
    HAVE_ANDROID_OS
    )

target_include_directories(binder PUBLIC include)

target_link_libraries(binder pthread)
