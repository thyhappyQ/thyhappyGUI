//
// Created by busil on 2026/4/30.
//

#include "../include/thyhappyGUI_menu.h"

int main() {
    const float a[4] = {0.0f,0.0f,0.2f,1.0f};

    thyhappySetTitle("Title");
    thyhappySetHeight(1000);
    thyhappySetWidth(1000);
    thyhappySetBackgroundColor(a);

    thyhappyInitialize();
    thyhappyMenuInitialize();

    const thyhappyMenuBlock aa = {"a",NULL};

    thyhappyMenuRegister(aa);

    while (!thyhappyWindowShouldClose()){}

    thyhappyCleanUp();
}