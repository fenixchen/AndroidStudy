cmake_minimum_required(VERSION 3.0)

project(Calc)

file(GLOB ICALC_SERVICE_AIDL test/ICalcService.aidl)

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/ICalcService.cpp
    COMMAND aidl-cpp -I${CMAKE_CURRENT_SOURCE_DIR} ${ICALC_SERVICE_AIDL}  ${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR}/ICalcService.cpp    
    DEPENDS ${ICALC_SERVICE_AIDL}
)

file(GLOB ICALC_CALLBACK_AIDL test/ICalcCallback.aidl)
add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/ICalcCallback.cpp    
    COMMAND aidl-cpp -I${CMAKE_CURRENT_SOURCE_DIR} ${ICALC_CALLBACK_AIDL}  ${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR}/ICalcCallback.cpp
    DEPENDS ${ICALC_CALLBACK_AIDL}
)


add_executable(calc_client 
    calc_client.cpp
    ICalcService.cpp
    ICalcCallback.cpp
    Rectangle.cpp
    CalcProto.cpp
)
target_include_directories(calc_client PRIVATE inc test .)
target_link_libraries(calc_client binder pthread)


add_executable(calc_server 
    calc_server.cpp 
    ICalcService.cpp
    ICalcCallback.cpp
    Rectangle.cpp    
    CalcProto.cpp
)
target_include_directories(calc_server PRIVATE inc test .)
target_link_libraries(calc_server binder pthread)