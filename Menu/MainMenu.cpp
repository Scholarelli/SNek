//
// Created by Emanuele Cianfanelli on 11/07/25.
//

//
// Created by Emanuele Cianfanelli on 18/03/25.
//

#include "MainMenu.h"

#include <cstring>

void MainMenu::render(WINDOW *win) {
    MenuBase::render(win);
}

UiAction MainMenu::getActionForIndex() {
    switch(this->selectedIndex) {
        case 0: return UI_CONTINUE_GAME;
        case 1: return UI_START_NEW_GAME;
        case 2: return UI_SHOW_LEADERBOARD;
        default: return UI_NO_ACTION;
    }
}


void MainMenu::resize(int width, int height) {
    return;
}
