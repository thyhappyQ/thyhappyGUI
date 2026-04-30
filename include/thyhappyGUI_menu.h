//
// Created by busil on 2026/4/30.
//

#ifndef THYHAPPYGUI_THYHAPPYGUI_MENU_H
#define THYHAPPYGUI_THYHAPPYGUI_MENU_H

#ifdef __cplusplus
extern "C" {
#endif

#include "thyhappyGUI_core.h"

struct _thyhappyMenuBlock {
    const char* name;
    const void(*callback)(); // When use press this block,program will give a callback
};

typedef struct _thyhappyMenuBlock thyhappyMenuBlock;

struct _tmb {
    thyhappyMenuBlock block;
    float pos[3];
};

typedef struct _tmb tmb;

extern BOOL tmInitialized;
extern BOOL tmRegistered;
extern tmb* mbArr;
extern unsigned int egDstc;
extern size_t step;

DLL void thyhappyMenuInitialize();
DLL void thyhappyMenuRegister(thyhappyMenuBlock block);
DLL void thyhappyMenuCleanUp();

DLL unsigned int* thyhappyMenuGetBlockSize();
DLL HWND thyhappyMenuGetHWND();

DLL void thyhappyMenuSetEdgeDistance(unsigned int edgeDistance);
DLL void thyhappyMenuSetBlockDistance(unsigned int blockDistance);

#ifdef __cplusplus
}
#endif

#endif //THYHAPPYGUI_THYHAPPYGUI_MENU_H