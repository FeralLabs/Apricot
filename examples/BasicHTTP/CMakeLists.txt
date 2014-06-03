cmake_minimum_required(VERSION 2.8)

project (basicHTTP)

set(APRICOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../..")
add_subdirectory(${APRICOT_PATH} "${CMAKE_CURRENT_BINARY_DIR}/build-apricot")

add_executable(basicHTTP main.cpp)
include_directories(${APRICOT_PATH}/include)
target_link_libraries(basicHTTP ${CMAKE_THREAD_LIBS_INIT} apricot)
