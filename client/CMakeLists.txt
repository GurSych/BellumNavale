cmake_minimum_required(VERSION 3.16)
project(BellumNavale)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(APP_VERSION_MAJOR   "0")
set(APP_VERSION_MINOR   "0")
set(APP_VERSION_PATCH   "1")
set(APP_VERSION_PRTAG   "Pre-Alpha")
set(APP_VERSION_prtag   "pre-alpha")

string(TIMESTAMP CMAKE_BUILD_TIME "%Y-%m-%d")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/config.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/include/config.hpp @ONLY)

include(FetchContent)

FetchContent_Declare(TinyColor
    GIT_REPOSITORY https://github.com/GurSych/TinyColor
    GIT_TAG        v2.0.0
)
FetchContent_MakeAvailable(TinyColor)

FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
    GIT_TAG        v6.1.9
)
FetchContent_MakeAvailable(ftxui)

add_executable(BellumNavale
    src/main.cpp
    src/core/Application.cpp
    src/game/BellumNavale.cpp
    src/game/BattleMap.cpp
)
set_target_properties(BellumNavale PROPERTIES OUTPUT_NAME "bellumnavale")

target_include_directories(BellumNavale PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(BellumNavale PRIVATE ${CMAKE_BINARY_DIR}/include)

target_link_libraries(BellumNavale PRIVATE TinyColor::TinyColor)
target_link_libraries(BellumNavale PRIVATE ftxui::component
                                           ftxui::dom
                                           ftxui::screen
)
