//
// Created by busil on 2026/4/30.
//

#ifndef THYHAPPYGUI_THYHAPPYGUI_MENU_H
#define THYHAPPYGUI_THYHAPPYGUI_MENU_H

#include "thyhappyGUI_core.h"

struct _thyhappyMenuBlock {
    const char* name;
    const void(*callback)(); // When use press this block,program will give a callback
};

typedef struct _thyhappyMenuBlock thyhappyMenuBlock;

struct _tmb {
    thyhappyMenuBlock block;
    int x;
    int y;
};

typedef struct _tmb tmb;

extern BOOL tmInitialized;
extern BOOL tmRegistered;
extern tmb* mbArr;

DLL void thyhappyMenuInitialize();
DLL void thyhappyMenuRegister(thyhappyMenuBlock block);
DLL void thyhappyMenuCleanUp();

DLL unsigned int* thyhappyMenuGetBlockSize();

#endif //THYHAPPYGUI_THYHAPPYGUI_MENU_H