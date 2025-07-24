//
// Created by Emanuele Cianfanelli on 09/07/25.
//


#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "MenuBase.h"

class PauseMenu : public MenuBase {
public:
    PauseMenu(int x, int y, int width, int height)
            : MenuBase(x, y, width ,height) {
        entriesNum = 3;
    }

    void render(WINDOW* win) override;

    const char* const* getEntries() const override {
        return entries;
    }

    int getEntriesCount() const override {
        return 3;  // Number of menu items
    }

    UiAction getSelectedAction() const;
    UiAction getActionForIndex() override;
private:
    static constexpr const char* entries[3] = {
        "Resume Game",
        "New Game",
        "Main Menu"
    };

};



#endif //PAUSEMENU_H
