cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_definitions("-DUNICODE" "-D_UNICODE")

add_executable(demo demo.cpp)
