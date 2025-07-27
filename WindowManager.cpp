#include "WindowManager.h"
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
        if (!handleInput()) {
            break;
        }

        // Control frame rate (50ms = ~20 FPS)
        usleep(50000);
    }

    cleanupNcurses();
}


void WindowManager::render() {


    if (gameWindow) {
        gameWindow->render(stdscr);
    }

    if (menu) {
        menu->render(menu->winPointer);

    }

    refresh();
}

void WindowManager::resize() {
    getmaxyx(stdscr, screenHeight, screenWidth);
    if (menu) {
        menu->recenter(screenWidth, screenHeight);
    }
}

bool WindowManager::handleInput() {
    controls input = get_user_input();

    if (input == QUIT) {
        return false;
    }
    if (input == RESIZE) {
        resize();
        render();
        return true;
    }

    focused->handleInput(input);
    return true;
}
