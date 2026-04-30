//
// Created by busil on 2026/4/30.
//

#ifndef THYHAPPYGUI_THYHAPPYGUI_EXPORT_H
#define THYHAPPYGUI_THYHAPPYGUI_EXPORT_H

#ifdef THYUHAPPYGUI_EXPORTS
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

#endif //THYHAPPYGUI_THYHAPPYGUI_EXPORT_H
