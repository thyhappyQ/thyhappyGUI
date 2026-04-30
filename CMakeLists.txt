cmake_minimum_required(VERSION 4.1)
project(thyhappyGUI C)

set(CMAKE_C_STANDARD 23)

add_executable(main src/main.c)
add_library(dll SHARED src/thyhappyGUI_core.c)
add_library(menuDll SHARED src/thyhappyGUI_menu.c)

target_compile_definitions(dll PRIVATE THYHAPPYGUI_EXPORTS)
target_compile_definitions(menuDll PRIVATE THYHAPPYGUI_EXPORTS)

target_link_libraries(menuDll dll)
target_link_libraries(main dll)
target_link_libraries(main menuDll)