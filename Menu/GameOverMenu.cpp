
#include "GameOverMenu.h"
#include <cstring>

void GameOverMenu::render(WINDOW *win) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 1, width/2 - 6, "GAME OVER!");

    const char *const*entries = getEntries();
    int numEntries = getEntriesCount();

    for (int i = 0; i < numEntries; ++i) {
        int entryY = 4 + i;  // Start a bit lower to make room for game over message
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

    wnoutrefresh(win);
}

UiAction GameOverMenu::getActionForIndex() {
    switch(this->selectedIndex) {
        case 0: return UI_START_NEW_GAME;  // Play Again
        case 1: return UI_MAIN_MENU;       // Main Menu
        case 2: return UI_QUIT_GAME;       // Quit Game
        default: return UI_NO_ACTION;
    }
}

void GameOverMenu::resize(int width, int height) {
    return;
}
