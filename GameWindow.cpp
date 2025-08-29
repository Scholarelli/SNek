#include "GameWindow.h"
#include "Levels.h"
#include "types.h"
#include <ncurses.h>
#include <ctime>



void GameWindow::spawn() const {
    buffer_->render(winPointer);
}

void GameWindow::draw() {
    updateBuffer();
}

void GameWindow::render(WINDOW *win) {
     buffer_->render(win);
    //wprintw(win, "GAME RENDERED");
}

void GameWindow::renderFull(WINDOW *win) {
    updateBuffer();
    buffer_->render(win, true);
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

//void GameWindow::setTile(int x, int y) const {
//    this->playfield_->setSnakeTile(x, y);
//}

void GameWindow::resize(int newWidth, int newHeight) {
    buffer_->resize(newWidth, newHeight);
    playfield_->resize(newWidth ,newHeight);
}

UiAction GameWindow::handleInput(controls input) {
    switch (input) {
        case MOVE_UP: snake->direction(0, -1); break;
        case MOVE_DOWN: snake->direction(0, 1); break;
        case MOVE_LEFT: snake->direction(-1, 0); break;
        case MOVE_RIGHT: snake->direction(1, 0); break;
        case LEVEL_UP:
            levels.nextLevel();
            snake = std::make_unique<SnakeMovement>(*playfield_, levels.getSnakeLength());
            break;
        case LEVEL_DOWN:
            levels.previousLevel();
            snake = std::make_unique<SnakeMovement>(*playfield_, levels.getSnakeLength());
            break;
        case FREEZE: return UI_PAUSE_GAME;
        case PAUSE: return UI_REQUEST_PAUSE;
        case QUIT: return UI_QUIT_GAME;
        default: return UI_NO_ACTION;
    }
    return UI_NO_ACTION;
}

void GameWindow::initializeWindow(WINDOW *parent) {

}

void GameWindow::update() {
    snake->step();
    updateBuffer();
}
