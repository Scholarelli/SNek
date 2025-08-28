#include "WindowManager.h"
#include "SnakeMovement.h"
#include <ncurses.h>
#include <unistd.h> // for usleep

WindowManager::WindowManager(int width, int height)
    : screenWidth(width), screenHeight(height), gameWindow(nullptr) {
}

WindowManager::~WindowManager() {
    if (gameWindow) {
        delete gameWindow;
    }
}

void WindowManager::initialize() {
    initializeNcurses();
    getmaxyx(stdscr, screenHeight, screenWidth);
    this->menu = new MainMenu(screenWidth / 2 - 30/2, screenHeight / 2 - 10/2);
    this->menu->initializeWindow(stdscr);
    this->focused = this->menu;
}

void WindowManager::createMenu() {
    WINDOW* chosenWindow = stdscr;
    if (gameWindow) {
        menu = new PauseMenu(screenWidth / 2 - 30/2, screenHeight / 2 - 10/2);
        chosenWindow = gameWindow->winPointer;
    } else {
        menu = new MainMenu(screenWidth / 2 - 30/2, screenHeight / 2 - 10/2);
    }


    if (menu) {
        menu->initializeWindow(chosenWindow);

        focused = menu;
    }
}

void WindowManager::deleteMenu() {
    if (!menu) return;
    delete menu;
    menu = nullptr;
    focused = gameWindow;

}
void WindowManager::initializeNcurses() {
    initscr();
    raw();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);

    // Initialize colors if available
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);   // Snake
        init_pair(2, COLOR_RED, COLOR_BLACK);     // Food
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);  // UI elements
        init_pair(4, COLOR_WHITE, COLOR_BLACK);   // Normal text
    }
}

void WindowManager::cleanupNcurses() {
    endwin();
}


void WindowManager::run() {
    while (true) {
        render();


        UiAction action = handleInput();
        if (action == UI_QUIT_GAME && !gameWindow) {
            break;
        }

        doupdate();
        switch (action) {
            case UI_NO_ACTION:
                if (menu == nullptr && gameWindow) {
                    gameWindow->update();
                } else if (menu != nullptr && gameWindow) {
                    gameWindow->draw();
                }
                break;
            case UI_START_NEW_GAME:
                if (gameWindow) {
                    delete gameWindow;
                }
                gameWidth = screenWidth;
                gameHeight = screenHeight;
                gameWindow = new GameWindow(screenWidth, screenHeight);
                deleteMenu();
                break;
            case UI_REQUEST_PAUSE:
                createMenu();
                break;
            case UI_RESUME_GAME:
                deleteMenu();
                break;
            case UI_QUIT_GAME:
            case UI_MAIN_MENU:
                if (gameWindow) {
                    delete gameWindow;
                    gameWindow = nullptr;
                    createMenu();
                } else {
                    cleanupNcurses();
                    return;
                }
                break;
            default: ;
        }

        // Control frame rate (50ms = ~20 FPS)
        usleep(50000);
    }

    cleanupNcurses();
}


void WindowManager::render() {
    if (resizeBlocked) {
        clear();

        int msgY = screenHeight / 2;
        int msgX = screenWidth / 2;

        const char* msg1 = "Terminal size changed!";
        const char* msg2 = "Please resize terminal back to original size to continue";
        const char* msg3 = "Press 'q' to quit";
        char sizeMsg[100];
        snprintf(sizeMsg, sizeof(sizeMsg), "Required size: %dx%d, Current: %dx%d",
                gameWidth, gameHeight, screenWidth, screenHeight);

        mvprintw(msgY - 2, msgX - strlen(msg1)/2, "%s", msg1);
        mvprintw(msgY - 1, msgX - strlen(sizeMsg)/2, "%s", sizeMsg);
        mvprintw(msgY, msgX - strlen(msg2)/2, "%s", msg2);
        mvprintw(msgY + 2, msgX - strlen(msg3)/2, "%s", msg3);

        refresh();
        return;

    }

    if (gameWindow) {
        gameWindow->render(gameWindow->winPointer);
    }

    if (menu) {
        menu->render(menu->winPointer);

    }

    doupdate();
}

void WindowManager::resize() {

    getmaxyx(stdscr, screenHeight, screenWidth);

    bool wasBlocked = resizeBlocked;
    if (gameWindow)
        resizeBlocked = screenHeight != gameHeight || screenWidth != gameWidth;
    if (wasBlocked && !resizeBlocked && gameWindow) {
        clear();
        refresh();
        gameWindow->renderFull(gameWindow->winPointer);
        doupdate();
    }

    if (menu) {
        menu->recenter(screenWidth, screenHeight);
    }
}

UiAction WindowManager::handleInput() {
    controls input = get_user_input();

    if (input == QUIT) {
        return UI_QUIT_GAME;
    }
    if (input == RESIZE) {
        resize();
        render();
        return UI_NO_ACTION;
    }

    if (resizeBlocked)
        return UI_NO_ACTION;

    return focused->handleInput(input);
}
