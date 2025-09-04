
#ifndef LEADERBOARDMENU_H
#define LEADERBOARDMENU_H

#include "MenuBase.h"

class LeaderboardMenu : public MenuBase {
public:
    struct LeaderboardEntry {
        int gameId;
        int score;
    };

    LeaderboardMenu(int x, int y, const LeaderboardEntry* entries, int numEntries, int width = 32)
            : MenuBase(x, y, width, calculateHeight(numEntries)), leaderboardEntries(entries), entryCount(numEntries) {
        entriesNum = 1;  // Just "Back to Main Menu" option
    }

    void render(WINDOW* win) override;

    const char* const* getEntries() const override {
        return entries;
    }

    int getEntriesCount() const override {
        return 1;  // Only one menu option
    }

    UiAction getActionForIndex() override;
    void resize(int width, int height) override;

    static int calculateHeight(int numEntries) {
        // Title(1) + spacing(1) + headers(2) + entries(numEntries) + separator(1) + menu_option(1) + borders(2)
        return 1 + 1 + 2 + numEntries + 1 + 1 + 2;
    }

private:
    const LeaderboardEntry* leaderboardEntries;
    int entryCount;

    static constexpr const char* entries[1] = {
        "Back to Main Menu"
    };
};

#endif //LEADERBOARDMENU_H
