//
// Created by busil on 2026/4/30.
//

#include "../include/thyhappyGUI_menu.h"

HWND hwnd = NULL;

LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

void static tmRegisterWindow() {
    // Set window class properties
    WNDCLASS wc = {0};
    wc.lpfnWndProc = wndProc;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "ThyhappyGUI Menu";

    // Do with error
    if (!RegisterClass(&wc)) {
        thyhappyError("Failed to register menu window class");
    }
}

void static tmCreateWindow() {

}

void static tmShowWindow() {

}

DLL inline void thyhappyMenuInitialize() {

}

DLL inline void thyhappyMenuRegister() {

}

DLL inline void thyhappyMenuCleanUp() {

}