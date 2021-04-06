cmake_minimum_required(VERSION 3.0)

project(protobuf_test)

set(PROTO_FILE person.proto)

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/person.pb-c.c
    COMMAND protoc-c --c_out=. ${PROTO_FILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS ${PROTO_FILE}
)

add_executable(protobuf_test
    protobuf_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/person.pb-c.c
)

target_link_libraries(protobuf_test binder pthread)
