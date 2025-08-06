
//#include "GameState.h"
#include "Menu/MainMenu.h"
#include "Menu/PauseMenu.h"
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

    MenuBase* menu = nullptr;
    GameWindow* gameWindow;

public:
    WindowManager(int width, int height);
    ~WindowManager();


    void initialize();

    void createMenu();

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