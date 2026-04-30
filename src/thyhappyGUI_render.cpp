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

        void initialize() {

        }
    }

    namespace render {

    }
}

DLL inline void thyhappyRenderDraw() {

}