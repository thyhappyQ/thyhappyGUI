//
// Created by busil on 2026/4/30.
//

#include "../include/thyhappyGUI_core.h"

int main() {
    thyhappyInitialize();
    while (!thyhappyWindowShouldClose()){}
    thyhappyCleanUp();
}