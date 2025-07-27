//
// Created by Emanuele Cianfanelli on 09/07/25.
//

#include "MenuBase.h"


#ifndef MAINMENU_H
#define MAINMENU_H

class MainMenu : public MenuBase {
public:
    MainMenu(int x, int y, int width = 30, int height = 10)
        : MenuBase(x, y, width ,height) {
        entriesNum = 3;
    }

    void render(WINDOW* win) override;
    UiAction getActionForIndex() override;

    void resize(int width, int height);

protected:

    const char* const* getEntries() const override {
        return entries;
    }

    int getEntriesCount() const override {
        return 3;
    }
private:
    static constexpr const char* entries[3] = {
        "Continue Game",
        "New Game",
        "Show Leaderboard"
    };


};

#endif //MAINMENU_H
