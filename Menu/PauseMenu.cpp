//
// Created by Emanuele Cianfanelli on 09/07/25.
//

#include "PauseMenu.h"
void PauseMenu::render(WINDOW *win) {
    MenuBase::render(win);
}

UiAction PauseMenu::getActionForIndex() {
    switch(this->selectedIndex) {
        case 0: return UI_RESUME_GAME;
        case 1: return UI_START_NEW_GAME;
        case 2: return UI_MAIN_MENU;
        default: return UI_NO_ACTION;
    }
}


void PauseMenu::resize(int width, int height) {
    return;
}
