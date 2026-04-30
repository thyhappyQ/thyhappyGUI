//
// Created by busil on 2026/4/30.
//

#include "../include/thyhappyGUI_menu.h"

int main() {
    thyhappySetTitle("Title");
    thyhappySetHeight(1000);
    thyhappySetWidth(1000);
    thyhappyInitialize();
    thyhappyMenuInitialize();
    while (!thyhappyWindowShouldClose()){}
    thyhappyCleanUp();
    thyhappyMenuCleanUp();
}