cmake_minimum_required(VERSION 3.16)
project(BellumNavale)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(APP_VERSION_MAJOR   "0")
set(APP_VERSION_MINOR   "0")
set(APP_VERSION_PATCH   "1")
set(APP_VERSION_PRTAG   "Pre-Alpha")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/config.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/include/config.hpp @ONLY)

add_executable(BellumNavale
    src/main.cpp
    src/core/Application.cpp
)

target_include_directories(BellumNavale PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(BellumNavale PRIVATE ${CMAKE_BINARY_DIR}/include)
