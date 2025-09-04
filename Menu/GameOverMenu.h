
#ifndef GAMEOVERMENU_H
#define GAMEOVERMENU_H

#include "MenuBase.h"

class GameOverMenu : public MenuBase {
public:
    GameOverMenu(int x, int y, int width = 30, int height = 12)
            : MenuBase(x, y, width, height) {
        entriesNum = 3;
    }

    void render(WINDOW* win) override;

    const char* const* getEntries() const override {
        return entries;
    }

    int getEntriesCount() const override {
        return 3;  // Number of menu items
    }

    UiAction getActionForIndex() override;
    void resize(int width, int height) override;

private:
    static constexpr const char* entries[3] = {
        "Play Again",
        "Main Menu",
        "Quit Game"
    };
};

#endif //GAMEOVERMENU_H
