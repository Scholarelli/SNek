//
// Created by Emanuele Cianfanelli on 08/07/25.
//
#include <curses.h>

#include "controls.h"
#include "UIAction.h"

#ifndef UIWINDOW_H
#define UIWINDOW_H
class UiWindow {
public:
    UiWindow(const int x, const int y, const int width, const int height)
        : x(x), y(y), width(width), height(height), winPointer(nullptr) {}

    virtual ~UiWindow() = default;

    virtual void render(WINDOW* win) = 0;
    virtual UiAction handleInput(controls input) = 0;
    virtual void resize(int width, int height) = 0;
    WINDOW* winPointer;

protected:
    int x, y, width, height;

    virtual void initializeWindow(WINDOW* parent) = 0;
    void cleanup();
};



#endif //UIWINDOW_H
