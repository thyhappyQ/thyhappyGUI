//
// Created by busil on 2026/5/1.
//

#ifndef THYHAPPYGUI_THYHAPPYGUI_CONFIG_H
#define THYHAPPYGUI_THYHAPPYGUI_CONFIG_H

// I use yyjson as JSON parser for now,I plan to use my own parser in future
#include <yyjson.h>

#include "thyhappyGUI_export.h"
#include "stdbool.h"

DLL void thyhappyConfigInitialize();
DLL bool thyhappyConfigWindowShouldClose();
DLL void thyhappyConfigCleanUp();

#endif //THYHAPPYGUI_THYHAPPYGUI_CONFIG_H
