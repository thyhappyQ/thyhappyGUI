//
// Created by busil on 2026/4/30.
//

#include "../include/thyhappyGUI_config.h"
#include "../include/thyhappyGUI_menu.h"

// This file is created to help me debug

int main() {
    thyhappyConfigInitialize();

    const thyhappyMenuBlock a = {"AAAAA",NULL};
    const thyhappyMenuBlock b = {"BBBB",NULL};
    const thyhappyMenuBlock c = {"CCC",NULL};
    const thyhappyMenuBlock d = {"DD",NULL};
    const thyhappyMenuBlock e = {"E",NULL};

    thyhappyMenuRegister(a);
    thyhappyMenuRegister(b);
    thyhappyMenuRegister(c);
    thyhappyMenuRegister(d);
    thyhappyMenuRegister(e);
    while (!thyhappyConfigWindowShouldClose()){}
    thyhappyConfigCleanUp();
}