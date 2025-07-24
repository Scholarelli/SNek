//
// Created by Emanuele Cianfanelli on 11/07/25.
//

#include "MenuBase.h"

#include <cstring>

void MenuBase::render(WINDOW *win) {
    wclear(win);  // Clear the window first
    box(win, 0, 0);  // Draw border

    mvwprintw(win, 1, width/2 - 4, "SNek Game");  // Move title down from line 0

    const char *const*entries = getEntries();
    int numEntries = getEntriesCount();

    for (int i = 0; i < numEntries; ++i) {  // Use int instead of size_t
        int entryY = 3 + i;  // Start from line 3 to avoid border
        int entryX = (width - strlen(entries[i])) / 2;

        if (i == selectedIndex) {
            wattron(win, A_REVERSE);
            mvwprintw(win, entryY, entryX - 2, "> %s <", entries[i]);
            wattroff(win, A_REVERSE);
        } else {
            mvwprintw(win, entryY, entryX, "%s", entries[i]);
        }
    }

    if (height > 6) {  // Only show instructions if window is big enough
        mvwprintw(win, height - 3, width/2 - 12, "Use Arrow Keys to Navigate");
        mvwprintw(win, height - 2, width/2 - 8, "Press Enter to Select");
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

