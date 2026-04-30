//
// Created by thyhappy on 2026/5/1.
//

#include "../include/thyhappyGUI_render.h"
#include "../include/thyhappyGUI_menu.h"
#include <d2d1.h>

#pragma comment(lib, "d2d1")

namespace thyhappy {
    ID2D1Factory* mf = nullptr; // Main factory
    ID2D1HwndRenderTarget* mrt = nullptr; // Main render target
    ID2D1HwndRenderTarget* mbrt = nullptr; // Menu block render target

    ID2D1SolidColorBrush* mbBrush = nullptr;

    namespace init {
        void createMainFactory(){
            D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &mf);
            if (!mf) {
                thyhappyError("Failed to create D2D factory");
            }
        }

        void createHwndRenderTarget() {
            // Get main window size
            RECT rect = {0};
            GetClientRect(thyhappyGetHWND(), &rect);

            // Save the window size in a size_u variable
            const D2D1_SIZE_U size = D2D1::SizeU(rect.right, rect.bottom);

            mf->CreateHwndRenderTarget(
                D2D1::RenderTargetProperties(),
                D2D1::HwndRenderTargetProperties(thyhappyGetHWND(),size),
                &mrt
                );
            if (!mrt) {
                thyhappyError("Failed to create render target");
            }
        }

        void createMenuHwndRenderTarget() {
            // Get main window size
            RECT rect = {0};
            GetClientRect(thyhappyMenuGetHWND(), &rect);

            // Save the window size in a size_u variable
            const D2D1_SIZE_U size = D2D1::SizeU(rect.right, rect.bottom);

            mf->CreateHwndRenderTarget(
                D2D1::RenderTargetProperties(),
                D2D1::HwndRenderTargetProperties(thyhappyMenuGetHWND(),size),
                &mbrt
                );
            if (!mbrt) {
                thyhappyError("Failed to create menu render target");
            }
        }

        void initMbBrush() {
            mbrt->CreateSolidColorBrush(
                D2D1::ColorF(
                    mbBkColor[0],
                    mbBkColor[1],
                    mbBkColor[2],
                    mbBkColor[3]),
                    &mbBrush);
            if (!mbBrush) {
                thyhappyError("Failed to create menu block brush");
            }
        }

        void initBrush() {
        }

        void initialize() {
            createMainFactory();
            createHwndRenderTarget();
            initBrush();
        }
    }

    namespace main {
        void drawBk() {
            // Draw background
            mrt->Clear(D2D1::ColorF(wBkColor[0],wBkColor[1],wBkColor[2],wBkColor[3]));
        }

        void drawMain() {
            mrt->BeginDraw();
            {
                // Real render code
                drawBk();
            }
            mrt->EndDraw();
        }
    }
    namespace menu {
        void drawBk() {
            mbrt->Clear(D2D1::ColorF(mbkColor[0],mbkColor[1],mbkColor[2],mbkColor[3]));
        }

        void drawMenuBlock() {
            // Draw all menu blocks
            for (unsigned int i = 0; i < step; i++) {
                mbrt->FillRoundedRectangle(
                   D2D1::RoundedRect(
                       D2D1::Rect(static_cast<float>(egDstc),mbArr[i].pos[0],mbArr[i].pos[1],mbArr[i].pos[2]),
                       10.0f,
                       10.0f
                       ),
                       mbBrush
                   );
            }
        }

        void drawMenu() {
            if (tmRegistered == TRUE) {
                mbrt->BeginDraw();

                drawBk();

                // If menu has at least one menu block
                drawMenuBlock();

                mbrt->EndDraw();
            }
        }
    }
}

extern "C" DLL void thyhappyRenderInitialize() {
    thyhappy::init::initialize();
}

extern "C" DLL void thyhappyRenderMenuInitialize() {
    thyhappy::init::createMenuHwndRenderTarget();
    thyhappy::init::initMbBrush();
}

extern "C" DLL void thyhappyRenderDraw() {
    thyhappy::main::drawMain();
    thyhappy::menu::drawMenu();
}