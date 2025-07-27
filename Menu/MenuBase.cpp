//
// Created by Emanuele Cianfanelli on 11/07/25.
//

#include "MenuBase.h"

#include <cstring>

void MenuBase::render(WINDOW *win) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 1, width/2 - 4, "SNek Game");

    const char *const*entries = getEntries();
    int numEntries = getEntriesCount();

    for (int i = 0; i < numEntries; ++i) {
        int entryY = 3 + i;
        int entryX = (width - strlen(entries[i])) / 2;
        if (entryX < 0)
            entryX = 0;

        if (i == selectedIndex) {
            wattron(win, A_REVERSE);
            mvwprintw(win, entryY, entryX - 2, "> %s <", entries[i]);
            wattroff(win, A_REVERSE);
        } else {
            mvwprintw(win, entryY, entryX, "%s", entries[i]);
        }
    }


    wrefresh(win);
}


void MenuBase::initializeWindow(WINDOW *win) {
    winPointer = subwin(win, height, width, y, x);
    box(winPointer, 0, 0);
    wrefresh(winPointer);

}

void MenuBase::moveUp() {
    if (selectedIndex > 0) {
        selectedIndex--;
    } else {
        selectedIndex = entriesNum - 1;
    }
}

void MenuBase::moveDown() {
    if (selectedIndex < entriesNum - 1) {
        selectedIndex++;
    } else {
        selectedIndex = 0;
    }
}

int MenuBase::getSelectedIndex() const {
    return selectedIndex;
}

void MenuBase::reset() {
    selectedIndex = 0;
}

void MenuBase::recenter(int screenWidth, int screenHeight) {
    this->x = screenWidth / 2 - this->width / 2;
    this->y = screenHeight / 2 - this->height / 2;


    if (winPointer) {
        // Clear the screen first
        clear();
        refresh();

        // Delete the old window completely
        delwin(winPointer);


    }
    winPointer = subwin(stdscr, height, width, y, x);

    if (winPointer) {
        // Redraw the window content
        box(winPointer, 0, 0);
        wrefresh(winPointer);
    }

}

void MenuBase::resize(int width, int height) {
    return;
}


UiAction MenuBase::handleInput(controls input) {
    switch (input) {
        case MOVE_UP:
            moveUp();
            return UI_NO_ACTION;
        case MOVE_DOWN:
            moveDown();
            return UI_NO_ACTION;
        case PAUSE:
            return getActionForIndex();
        default:
            return UI_NO_ACTION;
    }
}

