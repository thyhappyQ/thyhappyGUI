//
// Created by busil on 2026/4/30.
//

#ifndef THYHAPPYGUI_THYHAPPYGUI_MENU_H
#define THYHAPPYGUI_THYHAPPYGUI_MENU_H

#include "thyhappyGUI_core.h"

extern BOOL tmInitialized;

struct _thyhappyMenuBlock {
    const char* name;
    const void(*callback)(); // When use press this block,program will give a callback
};

typedef struct _thyhappyMenuBlock thyhappyMenuBlock;

DLL void thyhappyMenuInitialize();
DLL void thyhappyMenuRegister();
DLL void thyhappyMenuCleanUp(thyhappyMenuBlock block);

#endif //THYHAPPYGUI_THYHAPPYGUI_MENU_H