#include "LeaderboardMenu.h"
#include <cstring>

void LeaderboardMenu::render(WINDOW *win) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 1, width/2 - 6, "LEADERBOARD");
    
    mvwprintw(win, 3, 2, "Rank  Game          Score");
    mvwprintw(win, 4, 2, "------------------------");
    
    for (int i = 0; i < entryCount; ++i) {
        mvwprintw(win, 5 + i, 2, " %2d   Game %-7d %5d", 
                  i + 1, 
                  leaderboardEntries[i].gameId, 
                  leaderboardEntries[i].score);
    }
    
    int separatorY = 5 + entryCount;
    mvwprintw(win, separatorY, 2, "------------------------");
    
    const char *const*entries = getEntries();
    int entryY = separatorY + 1;
    int entryX = (width - strlen(entries[0])) / 2;
    if (entryX < 0) entryX = 0;
    
    if (selectedIndex == 0) {
        wattron(win, A_REVERSE);
        mvwprintw(win, entryY, entryX - 2, "> %s <", entries[0]);
        wattroff(win, A_REVERSE);
    } else {
        mvwprintw(win, entryY, entryX, "%s", entries[0]);
    }

    wnoutrefresh(win);
}

UiAction LeaderboardMenu::getActionForIndex() {
    switch(this->selectedIndex) {
        case 0: return UI_MAIN_MENU;
        default: return UI_NO_ACTION;
    }
}

void LeaderboardMenu::resize(int width, int height) {
    return;
}
