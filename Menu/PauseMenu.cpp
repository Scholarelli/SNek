//
// Created by Emanuele Cianfanelli on 09/07/25.
//

#include "PauseMenu.h"
void PauseMenu::render(WINDOW *win) {
    MenuBase::render(win);
}

UiAction PauseMenu::getActionForIndex() {
    return UI_NO_ACTION;
}

UiAction PauseMenu::getSelectedAction() const {
    return UI_NO_ACTION;
}


