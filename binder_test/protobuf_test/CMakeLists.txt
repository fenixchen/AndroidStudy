cmake_minimum_required(VERSION 3.0)

project(protobuf_test)



file(GLOB PROTO_FILE person.proto)

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/person.pb.cc
    COMMAND protoc --cpp_out=. person.proto
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS ${CALC_COMMAND_PROTO}
)

add_executable(protobuf_test
    protobuf_test.cpp
    person.pb.cc
)

target_link_libraries(protobuf_test protobuf pthread)
