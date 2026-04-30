//
// Created by thyhappy on 2026/4/30.
//

#ifndef THYHAPPYGUI_THYHAPPYGUI_CORE_H
#define THYHAPPYGUI_THYHAPPYGUI_CORE_H

#include <windows.h>

#include "thyhappyGUI_export.h"

// Base functions
DLL void thyhappyInitialize();
DLL BOOL thyhappyWindowShouldClose();
DLL void thyhappyCleanUp();

// Call a message window to show error
DLL void thyhappyError(const char* content);

// Get main window HWND
DLL HWND thyhappyGetHWND();

// Functions for user
DLL void thyhappySetTitle(const char* title);
DLL void thyhappySetWidth(int width);
DLL void thyhappySetHeight(int height);
DLL void thyhappySetPosition(int x, int y);
DLL void thyhappySetBackgroundColor(const float color[4]);

// Public global variables
extern int wWidth;
extern int wHeight;
extern const char* wTitle;
extern float wBkColor[4];
extern int wX;
extern int wY;

#endif //THYHAPPYGUI_THYHAPPYGUI_CORE_H