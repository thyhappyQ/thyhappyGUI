cmake_minimum_required(VERSION 4.1)
project(thyhappyGUI C)

set(CMAKE_C_STANDARD 23)

add_executable(main src/main.c)
add_library(dll SHARED src/thyhappyGUI_core.c)
add_library(menuDll SHARED src/thyhappyGUI_menu.c)
add_library(menuPrivateDll SHARED src/thyhappyGUI_menu_private.c)

target_link_libraries(main dll)