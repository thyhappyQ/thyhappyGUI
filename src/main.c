//
// Created by busil on 2026/4/30.
//

#include "../include/thyhappyGUI_config.h"

// This file is created to help me debug

int main() {
    thyhappyConfigInitialize();
    while (!thyhappyConfigWindowShouldClose()){}
    thyhappyConfigCleanUp();
}