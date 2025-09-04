#include "LeaderboardMenu.h"
#include <cstring>

void LeaderboardMenu::render(WINDOW *win) {
    wclear(win);
    box(win, 0, 0);

    // Title
    mvwprintw(win, 1, width/2 - 6, "LEADERBOARD");
    
    // Headers
    mvwprintw(win, 3, 2, "Rank  Name          Score");
    mvwprintw(win, 4, 2, "------------------------");
    
    // Display leaderboard entries
    for (int i = 0; i < 8; ++i) {
        mvwprintw(win, 5 + i, 2, " %2d   %-12s %5d", 
                  i + 1, 
                  leaderboard[i].name, 
                  leaderboard[i].score);
    }
    
    // Separator line before menu option
    mvwprintw(win, 13, 2, "------------------------");
    
    // Menu option
    const char *const*entries = getEntries();
    int entryY = 14;
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
        case 0: return UI_MAIN_MENU;  // Back to Main Menu
        default: return UI_NO_ACTION;
    }
}

void LeaderboardMenu::resize(int width, int height) {
    return;
}
