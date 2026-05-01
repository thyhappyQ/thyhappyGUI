//
// Created by busil on 2026/5/1.
//

#include "../include/thyhappyGUI_config.h"

#include "../include/thyhappyGUI_menu.h"

#define DEFAULT_WINDOW_CONFIG_PATH "thyhappy_window.json"
#define DEFAULT_MENU_CONFIG_PATH "thyhappy_menu.json"

#define WIDTH_KEY "width"
#define HEIGHT_KEY "height"
#define TITLE_KEY "title"
#define BKCOLOR_KEY "bkcolor"

#define M_WIDTH_KEY "width"
#define M_BKCOLOR_KEY "bkcolor"
#define M_MKBKCOLOR_KEY "mbbkcolor"
#define M_EGDSTC_KEY "egdstc" // Edge distance
#define M_BLDSTC_KEY "bldstc" // Block distance
#define M_MBFONTCOLOR_KEY "fontcolor"

yyjson_doc* wDoc = NULL;
yyjson_doc* mDoc = NULL;

void static tEzReadCol(yyjson_val* root,const char* key,float* tarr) {
    // This function helps me read the color array easily

    yyjson_val* colArr = yyjson_obj_get(root,key);

    for (unsigned int i = 0; i < yyjson_arr_size(colArr); i++) {
        tarr[i] = (float)yyjson_get_num(yyjson_arr_get(colArr,i));
    }
}

void static tReadWindowConfig() {
    wDoc = yyjson_read_file(DEFAULT_WINDOW_CONFIG_PATH,0,NULL,NULL);
    if (!wDoc) {
        thyhappyError("Failed to read window config file");
        return;
    }

    // Get root
    yyjson_val* root = yyjson_doc_get_root(wDoc);

    // Read data
    wWidth = yyjson_get_int(yyjson_obj_get(root,WIDTH_KEY));
    wHeight = yyjson_get_int(yyjson_obj_get(root,HEIGHT_KEY));
    wTitle = yyjson_get_str(yyjson_obj_get(root,TITLE_KEY));

    // Read array
    yyjson_val* bkArr = yyjson_obj_get(root,BKCOLOR_KEY);
    float buffer[4] = {0};
    for (size_t i = 0; i < yyjson_arr_size(bkArr); i++) {
        buffer[i] = (float)yyjson_get_num(yyjson_arr_get(bkArr,i));
    }
    thyhappySetBackgroundColor(buffer);
}

void static tReadMenuConfig() {
    mDoc = yyjson_read_file(DEFAULT_MENU_CONFIG_PATH,0,NULL,NULL);
    if (!mDoc) {
        thyhappyError("Failed to read menu config file");
        return;
    }

    yyjson_val* root = yyjson_doc_get_root(mDoc);

    thyhappyMenuSetWidth(yyjson_get_int(yyjson_obj_get(root,M_WIDTH_KEY)));
    thyhappyMenuSetEdgeDistance(yyjson_get_int(yyjson_obj_get(root,M_EGDSTC_KEY)));
    thyhappyMenuSetBlockDistance(yyjson_get_int(yyjson_obj_get(root,M_BLDSTC_KEY)));

    // Read array
    float menuBkColor[4] = {0};
    float menuBlockBkColor[4] = {0};
    float menuBlockFontColor[4] = {0};

    tEzReadCol(root,M_BKCOLOR_KEY,menuBkColor);
    tEzReadCol(root,M_MKBKCOLOR_KEY,menuBlockBkColor);
    tEzReadCol(root,M_MBFONTCOLOR_KEY,menuBlockFontColor);

    thyhappyMenuSetBkColor(menuBkColor);
    thyhappyMenuSetMbBkColor(menuBlockBkColor);
    thyhappyMenuSetMbFontColr(menuBlockFontColor);
}

DLL void thyhappyConfigInitialize() {
    tReadWindowConfig();
    tReadMenuConfig();

    thyhappyInitialize();
    thyhappyMenuInitialize();
}

DLL bool thyhappyConfigWindowShouldClose() {
    return thyhappyWindowShouldClose();
}

DLL void thyhappyConfigCleanUp() {
    yyjson_doc_free(wDoc);
    yyjson_doc_free(mDoc);
    thyhappyCleanUp();
}