
//#include "GameState.h"
#include "Menu/MainMenu.h"
#include "Menu/PauseMenu.h"
#include "Menu/GameOverMenu.h"
#include "Menu/LeaderboardMenu.h"
#include "GameWindow.h"
#include "controls.h"
#include "SnakeMovement.h"

#include <ncurses.h>
#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

class WindowManager {
private:
    UiWindow* focused = nullptr;
    int screenWidth, screenHeight;
    int gameWidth = 0, gameHeight = 0;
    bool resizeBlocked = false;

    MenuBase* menu = nullptr;
    GameWindow* gameWindow;

public:
    WindowManager(int width, int height);
    ~WindowManager();


    void initialize();

    void createMenu();
    void createGameOverMenu();
    void createLeaderboardMenu();

    void deleteMenu();

    void resize();
    void run();



    // Main loop methods
    void render();
    UiAction handleInput();

    static void initializeNcurses();

private:
    void cleanupNcurses();
};

#endif //WINDOWMANAGER_H