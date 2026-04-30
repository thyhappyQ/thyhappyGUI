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
// Because I plan to public this function only for developer now,
// so I do not export it in DLL
void thyhappyError(const char* content);

// Get main window HWND
DLL HWND thyhappyGetHWND();

// Functions for user
DLL void thyhappySetTitle(const char* title);
DLL void thyhappySetWidth(int width);
DLL void thyhappySetHeight(int height);
DLL void thyhappySetPosition(int x, int y);

#endif //THYHAPPYGUI_THYHAPPYGUI_CORE_H