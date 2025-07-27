//
// Created by Emanuele Cianfanelli on 09/07/25.
//

#ifndef MENUBASE_H
#define MENUBASE_H
#include <curses.h>

#include "../UiWindow.h"



class MenuBase : public UiWindow {
public:

    MenuBase(int x, int y, int width, int height) : UiWindow(x, y, width, height) {
        winPointer = nullptr;
    }
    ~MenuBase() override {
        if (winPointer) {
            wclear(winPointer);
            delwin(winPointer);
        }
    }
    void render(WINDOW* win) override;
    UiAction handleInput(controls input) override;
    void initializeWindow(WINDOW *parent) override;
    void recenter(int x, int y);

    void resize(int width, int height) override = 0;
protected:
    int selectedIndex = 0;
    int entriesNum = 0;
    virtual const char* const* getEntries() const = 0;
    virtual int getEntriesCount() const = 0;

    void moveUp();
    void moveDown();
    int getSelectedIndex() const;

    virtual UiAction getActionForIndex() = 0;
    void reset();
};

#endif //MENUBASE_H
