cmake_minimum_required(VERSION 3.16)

project(client)

set(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

message("building client...")

add_executable(client1 client1.cpp)
add_executable(client2 client2.cpp)
add_executable(io_file io_file.cpp)
add_executable(test test.cpp)
