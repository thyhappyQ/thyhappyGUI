//
// Created by thyhappy on 2026/4/30.
//

#ifndef THYHAPPYGUI_THYHAPPYGUI_CORE_H
#define THYHAPPYGUI_THYHAPPYGUI_CORE_H

#include <windows.h>

#include "thyhappyGUI_export.h"

// Base functions
DLL void thyhappyInitialize();
DLL void thyhappyMainLoop();
DLL void thyhappyCleanUp();

// Call a message window to show error
// Because I plan to public this function only for developer now,
// so I do not export it in DLL
void thyhappyError(const char* content);

// Get main window HWND
DLL HWND thyhappyGetHWND();

#endif //THYHAPPYGUI_THYHAPPYGUI_CORE_H