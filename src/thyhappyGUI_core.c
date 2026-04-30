//
// Created by thyhappy on 2026/4/30.
//

#include "../include/thyhappyGUI_core.h"

LRESULT CALLBACK wndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam) {
    switch (msg) {
        default: return DefWindowProc(hwnd,msg,wParam,lParam);
    }
}

void thyhappyError(const char* content) {
    MessageBox(nullptr, content, "Error", MB_OK | MB_ICONERROR);
}

void static tRegisterWindow() {
    // Register a window
    WNDCLASS wc = {0};

    // Set window class properties
    wc.lpszClassName = "ThyhappyGUI";
    wc.lpfnWndProc = wndProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

    // Do with error
    if (!RegisterClass(&wc)) {
        thyhappyError("Failed to register window class");
    }
}

DLL inline HWND thyhappyGetHWND() {
    return Hwnd;
}

void static tCreateWindow() {

}

DLL inline void thyhappyInitialize() {
    /* Implement core initialize function */

    tRegisterWindow();
}