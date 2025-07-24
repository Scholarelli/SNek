//
// Created by Emanuele Cianfanelli on 11/07/25.
//

//
// Created by Emanuele Cianfanelli on 18/03/25.
//

#include "MainMenu.h"

#include <cstring>

void MainMenu::render(WINDOW *win) {
    wclear(win);  // Clear the window first
    box(win, 0, 0);  // Draw border

    mvwprintw(win, 1, width/2 - 4, "SNek Game");  // Move title down from line 0

    const char *const*entries = getEntries();
    int numEntries = getEntriesCount();

    for (int i = 0; i < numEntries; ++i) {  // Use int instead of size_t
        int entryY = 3 + i;  // Start from line 3 to avoid border
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
    wrefresh(win);

    }


    wrefresh(win);
}

UiAction MainMenu::getActionForIndex() {
    switch(this->selectedIndex) {
        case 0: return UI_CONTINUE_GAME;
        case 1: return UI_START_NEW_GAME;
        case 2: return UI_SHOW_LEADERBOARD;
        default: return UI_NO_ACTION;
    }
}

