#include "GameWindow.h"
#include <ncurses.h>

#include "types.h"


void GameWindow::initialize() {
    initscr();
    raw();
    noecho();
    //nodelay(stdscr, TRUE);
    timeout(1000);
    keypad(stdscr, TRUE);

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    curs_set(0);
}

void GameWindow::spawn() const {
    buffer_->render(stdscr);
}

void GameWindow::draw() {
    updateBuffer();
}

void GameWindow::render(WINDOW *win) const {

    buffer_->render(win);
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

void GameWindow::resize(int x, int y) {
    buffer_->resize(x, y);
    playfield_->resize(x ,y);
}


