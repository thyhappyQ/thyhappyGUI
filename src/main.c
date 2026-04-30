//
// Created by busil on 2026/4/30.
//

#include "../include/thyhappyGUI_menu.h"

// This file is created to help me debug

int main() {
    const float a[4] = {0.1f,0.1f,0.1f,1.0f};

    thyhappySetTitle("Title");
    thyhappySetHeight(1000);
    thyhappySetWidth(1000);
    thyhappySetBackgroundColor(a);

    thyhappyMenuSetBlockDistance(10);
    thyhappyMenuSetEdgeDistance(10);

    thyhappyInitialize();
    thyhappyMenuInitialize();

    const thyhappyMenuBlock aa = {"a",NULL};

    thyhappyMenuRegister(aa);
    thyhappyMenuRegister(aa);

    while (!thyhappyWindowShouldClose()){}

    thyhappyCleanUp();
}