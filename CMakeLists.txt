cmake_minimum_required(VERSION 4.1)
project(thyhappyGUI C CXX)

set(CMAKE_C_STANDARD 23)

find_package(yyjson CONFIG REQUIRED)

add_executable(main src/main.c)
add_library(dll SHARED src/thyhappyGUI_core.c src/thyhappyGUI_render.cpp src/thyhappyGUI_menu.c src/thyhappyGUI_config.c)

target_compile_definitions(dll PRIVATE THYHAPPYGUI_EXPORTS)

target_link_libraries(main PRIVATE dll)
target_link_libraries(dll PRIVATE yyjson::yyjson)