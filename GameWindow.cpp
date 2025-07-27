#include "GameWindow.h"
#include <ncurses.h>

#include "types.h"



void GameWindow::spawn() const {
    buffer_->render(stdscr);
}

void GameWindow::draw() {
    updateBuffer();
}

void GameWindow::render(WINDOW *win) {

    buffer_->render(win);
    wprintw(win, "GAME RENDERED");

}

void GameWindow::updateBuffer() const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (playfield_->isSnakeAt(x, y)) {
                buffer_->setTile(x, y, 'O', 1, true);  // Green for snake
            } else if (playfield_->isFoodAt(x, y)) {
                buffer_->setTile(x, y, '*', 2, false); // Red for food
            } else {
                buffer_->setTile(x, y, ' ', 0, false); // Empty space
            }
        }
    }
}

void GameWindow::setTile(int x, int y) const {
    this->playfield_->setSnakeTile(x, y);
}

void GameWindow::resize(int newWidth, int newHeight) {
    buffer_->resize(newWidth, newHeight);
    playfield_->resize(newWidth ,newHeight);
}

UiAction GameWindow::handleInput(controls input) {
    switch (input) {
        case FREEZE: return UI_PAUSE_GAME;
        case PAUSE: return UI_REQUEST_PAUSE;
        case QUIT: return UI_QUIT_GAME;
        default: return UI_NO_ACTION;
    }

}

void GameWindow::initializeWindow(WINDOW *parent) {

}
