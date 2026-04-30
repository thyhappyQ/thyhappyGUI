//
// Created by busil on 2026/4/30.
//
#include "../include/thyhappyGUI_menu.h"

HWND hwnd = NULL;

#define DEFAULT_M_W_W 200 // Width

int width = DEFAULT_M_W_W;
int height = 0;

LRESULT CALLBACK mWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
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
    wc.lpfnWndProc = mWndProc;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "ThyhappyGUI Menu";

    // Do with error
    if (!RegisterClass(&wc)) {
        thyhappyError("Failed to register menu window class");
    }
}

void static tmCreateWindow() {
    // Get main window size
    RECT mainRect = {0};
    GetClientRect(thyhappyGetHWND(), &mainRect);

    // Menu window's height is as the same as main window
    height = mainRect.bottom - mainRect.top;
    hwnd = CreateWindow(
        "ThyhappyGUI Menu",
        "Menu Title",
        WS_CHILD,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        width,
        height,
        thyhappyGetHWND(),
        NULL,
        GetModuleHandle(NULL),
        NULL
        );

    // Check
    if (!hwnd) {
        thyhappyError("Failed to create menu window");
    }
}

void static tmShowWindow() {
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
}

DLL inline void thyhappyMenuInitialize() {
    tmRegisterWindow();
    tmCreateWindow();
    tmShowWindow();
}

DLL inline void thyhappyMenuRegister() {
    if (TRUE){}
}

DLL inline void thyhappyMenuCleanUp() {
    if (TRUE){}
}