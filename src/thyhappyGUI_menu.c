//
// Created by busil on 2026/4/30.
//
#include "../include/thyhappyGUI_menu.h"

#include <stdlib.h>

HWND hwnd = NULL;

#define DEFAULT_M_W_W 200 // Width

#define MB_ARR_SIZE 10

int width = DEFAULT_M_W_W;
int height = 0;

BOOL tmInitialized = FALSE;
BOOL tmRegistered = FALSE;
tmb* mbArr = NULL;

size_t step = 0;
size_t alloced = MB_ARR_SIZE;

unsigned int blockSize[2] = {0};

unsigned int egDstc = 0;
unsigned int blDstc = 0;

float mbkColor[4] = {0.0f, 0.0f, 0.0f, 0.0f};
float mbBkColor[4] = {0.3f, 0.3f, 0.4f, 0.5f};

float mbFtColor[4] = {1.0f, 1.0f, 1.0f, 1.0f};

float mbFontSize = 30.0f;
float mbFontDstc = 5.0f;

void (*afterRgsCallback)()=NULL;

DLL void thyhappyMenuSetMbFontColr(const float mbFontColr[4]) {
    mbFtColor[0] = mbFontColr[0];
    mbFtColor[1] = mbFontColr[1];
    mbFtColor[2] = mbFontColr[2];
    mbFtColor[3] = mbFontColr[3];
}

DLL void thyhappyMenuSetMbFontDstc(const float new_font_dstc) {
    mbFontDstc = new_font_dstc;
}

LRESULT CALLBACK mWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_LBUTTONDOWN:
            // If click one the menu blocks,call it back

            // Get screen position
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            ScreenToClient(hwnd, &cursorPos);

            // Turn screen position to client position
            const int x = cursorPos.x;
            const int y = cursorPos.y;

            for (size_t i = 0; i < step; i++) {
                if (x >= egDstc && (float)x <= mbArr[i].pos[1] && (float)y >= mbArr[i].pos[0] && (float)y <= mbArr[i].pos[2]) {
                    mbArr[i].block.callback();
                }
            }

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

DLL void thyhappyMenuInitialize() {
    tmRegisterWindow();
    tmCreateWindow();
    tmShowWindow();

    thyhappyRenderMenuInitialize();

    tmInitialized = TRUE;
}

DLL unsigned int* thyhappyMenuGetBlockSize() {
    return blockSize;
}

DLL void thyhappyMenuSetMbFontSize(const float new_font_size) {
    mbFontSize = new_font_size;
}

DLL void thyhappyMenuSetBlockDistance(unsigned int blockDistance) {
    blDstc = blockDistance;
}

DLL void thyhappyMenuSetEdgeDistance(unsigned int edgeDistance) {
    egDstc = edgeDistance;
}

DLL void thyhappyMenuRegister(const thyhappyMenuBlock block) {
    if (tmRegistered == FALSE) {
        tmRegistered = TRUE;

        // Init menu block array
        mbArr = calloc(MB_ARR_SIZE, sizeof(tmb));
        if (!mbArr) {
            thyhappyError("Failed to allocate memory for menu block");
            return;
        }

        // Work out each block's size
        {
            // Work out the width of block
            if (width > 2 * egDstc) {
                blockSize[0] = width - 2 * egDstc;
            }

            // Work out the height
            // Default height of the menu block is the 1/10 of window height
            if (height > 2 * egDstc) {
                blockSize[1] = height / 10;
            }
        }
    }

    // Put arg block into array
    {
        // Check if the memory is big enough
        if (step + 1 == alloced) {
            // Alloc new memory
            tmb* newMem = realloc(mbArr, (step + MB_ARR_SIZE) * sizeof(tmb));
            if (!newMem) {
                thyhappyError("Failed to allocate new memory for menu block");
                return;
            }
            mbArr = newMem;
        }

        // Put
        mbArr[step].block = block;

        // Work out the y position of this block
        // Y = blDstc + (step + 1)*menuBlockHeight
        // SO :

        // X in left = egDstc
        mbArr[step].pos[0] = (float)(egDstc +  step * (blockSize[1] + blDstc)); // Y in left
        mbArr[step].pos[1] = (float)(egDstc + blockSize[0]); // X in right
        mbArr[step].pos[2] = mbArr[step].pos[0] + (float)blockSize[1]; // Y in right
    }

    // Add counter
    step++;
}
DLL void thyhappyMenuSetWidth(const int new_width) {
    width = new_width;
}

DLL void thyhappyMenuSetBkColor(const float color[4]) {
    mbkColor[0] = color[0];
    mbkColor[1] = color[1];
    mbkColor[2] = color[2];
    mbkColor[3] = color[3];
}

DLL void thyhappyMenuSetMbBkColor(const float color[4]) {
    mbBkColor[0] = color[0];
    mbBkColor[1] = color[1];
    mbBkColor[2] = color[2];
    mbBkColor[3] = color[3];
}

DLL HWND thyhappyMenuGetHWND() {
    return hwnd;
}

DLL void thyhappyMenuCleanUp() {
    free(mbArr);
}