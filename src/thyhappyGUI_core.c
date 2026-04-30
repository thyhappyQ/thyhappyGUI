//
// Created by thyhappy on 2026/4/30.
//

#include "../include/thyhappyGUI_core.h"

HWND Hwnd = nullptr;

#define DEFAULT_WINDOW_TITLE "Default title"
#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 800
#define DEFAULT_WINDOW_POS CW_USEDEFAULT

int wWidth = DEFAULT_WINDOW_WIDTH;
int wHeight = DEFAULT_WINDOW_HEIGHT;
const char* wTitle = DEFAULT_WINDOW_TITLE;

// Window positions
int wX = DEFAULT_WINDOW_POS;
int wY = DEFAULT_WINDOW_POS;

DLL inline void thyhappySetTitle(const char* title) {
    wTitle = title == nullptr ? "" : title;
}

DLL inline void thyhappySetWidth(const int width) {
    wWidth = width;
}

DLL inline void thyhappySetHeight(const int height) {
    wHeight = height;
}

DLL inline void thyhappySetPosition(const int x, const int y) {
    wX = x < 0 ? 0 : x;
    wY = y < 0 ? 0 : y;
}

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
    Hwnd = CreateWindow(
        "ThyhappyGUi",
        wTitle,
        WS_OVERLAPPEDWINDOW,
        wX,
        wY,
        wWidth,
        wHeight,
        nullptr,
        nullptr,
        GetModuleHandle(nullptr),
        nullptr
        );

    // Do with error
    if (!Hwnd) {
        thyhappyError("Failed to create window");
    }
}

void static tShowWindow() {
    // Show window
    ShowWindow(Hwnd,SW_SHOW);
    UpdateWindow(Hwnd);
}

DLL inline void thyhappyInitialize() {
    /* Implement core initialize function */

    tRegisterWindow();
    tCreateWindow();
    tShowWindow();
}

DLL inline void thyhappyWindowShouldClose() {

}

DLL inline void thyhappyCleanUp() {

}