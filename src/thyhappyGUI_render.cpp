//
// Created by thyhappy on 2026/5/1.
//

#include "../include/thyhappyGUI_render.h"

#include <d2d1.h>

#pragma comment(lib, "d2d1")

namespace thyhappy {
    ID2D1Factory* mf = nullptr; // Main factory
    ID2D1HwndRenderTarget* mrt = nullptr; // Main render target

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

        void initialize() {
            createMainFactory();
            createHwndRenderTarget();
        }
    }

    namespace render {
        void drawBk() {
            // Draw background
            mrt->Clear(D2D1::ColorF(wBkColor[0],wBkColor[1],wBkColor[2],wBkColor[3]));
        }
    }
}

extern "C" DLL inline void thyhappyRenderInitialize() {
    thyhappy::init::initialize();
}

extern "C" DLL inline void thyhappyRenderDraw() {
    thyhappy::mrt->BeginDraw();
    {
        // Real render code
        thyhappy::render::drawBk();
    }
    thyhappy::mrt->EndDraw();
}