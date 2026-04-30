//
// Created by thyhappy on 2026/4/30.
//

#define THYHAPPYGUI_EXPORTS

#include "../include/thyhappyGUI_core.h"

HWND Hwnd = NULL;

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

MSG msg = {0};

DLL inline void thyhappySetTitle(const char* title) {
    wTitle = title == NULL ? "" : title;
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
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default: return DefWindowProc(hwnd,msg,wParam,lParam);
    }
}

void thyhappyError(const char* content) {
    MessageBox(NULL, content, "Error", MB_OK | MB_ICONERROR);
}

void static tRegisterWindow() {
    // Register a window
    WNDCLASS wc = {0};

    // Set window class properties
    wc.lpszClassName = "ThyhappyGUI";
    wc.lpfnWndProc = wndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

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
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
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

void static tDoWithInput() {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}

DLL inline BOOL thyhappyWindowShouldClose() {
    PeekMessage(&msg,NULL,0,0,PM_REMOVE);
    if (msg.message == WM_QUIT) {
        return TRUE;
    }
    tDoWithInput();
    return FALSE;
}

DLL inline void thyhappyCleanUp() {

}