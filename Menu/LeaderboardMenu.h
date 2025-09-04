
#ifndef LEADERBOARDMENU_H
#define LEADERBOARDMENU_H

#include "MenuBase.h"

class LeaderboardMenu : public MenuBase {
public:
    LeaderboardMenu(int x, int y, int width = 32, int height = 16)
            : MenuBase(x, y, width, height) {
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

private:
    static constexpr const char* entries[1] = {
        "Back to Main Menu"
    };
    
    // Placeholder leaderboard data
    struct LeaderboardEntry {
        const char* name;
        int score;
    };
    
    static constexpr LeaderboardEntry leaderboard[8] = {
        {"Player1", 2500},
        {"Snake_Master", 2100},
        {"QuickBite", 1850},
        {"Serpent_King", 1600},
        {"SlitherPro", 1400},
        {"CoilMaster", 1200},
        {"VenomStrike", 1000},
        {"TailChaser", 800}
    };
};

#endif //LEADERBOARDMENU_H
