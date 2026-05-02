//
// Created by busil on 2026/4/30.
//

#include "../include/thyhappyGUI_config.h"
#include "../include/thyhappyGUI_menu.h"

// This file is created to help me debug

int main() {
    thyhappyConfigInitialize();

    const thyhappyMenuBlock a = {"aaa",NULL};
    const thyhappyMenuBlock b = {"bbb",NULL};

    thyhappyMenuRegister(a);
    thyhappyMenuRegister(b);
    while (!thyhappyConfigWindowShouldClose()){}
    thyhappyConfigCleanUp();
}