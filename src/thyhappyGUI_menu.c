//
// Created by busil on 2026/4/30.
//

#include "../include/thyhappyGUI_menu.h"

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
    WNDCLASS wc = {0};

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