#include "GameWindow.h"
#include "Levels.h"
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

    int maxY = getmaxy(win);
    int maxX = getmaxx(win);

    int remaining = timeTot - timeDone;
    mvwprintw(win, maxY - 1, 1, "Score: %d | Time: %d/%d", score, remaining, timeTot);

    mvwprintw(win, maxY - 1, maxX - 10, "Level: %d",levels.getLevel());


    wnoutrefresh(win);
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
    // buffer_->resize(newWidth, newHeight);
    // playfield_->resize(newWidth ,newHeight);
}

UiAction GameWindow::handleInput(controls input) {
    switch (input) {
        case MOVE_UP: snake->direction(0, -1); break;
        case MOVE_DOWN: snake->direction(0, 1); break;
        case MOVE_LEFT: snake->direction(-1, 0); break;
        case MOVE_RIGHT: snake->direction(1, 0); break;
        case LEVEL_UP:
            if (levels.nextLevel()) {
                delete snake;
                snake = new SnakeMovement(*playfield_, levels.getSnakeLength());
                fruitCounter = 0;
            }
            break;
        case LEVEL_DOWN:
            if (levels.previousLevel()) {
                delete snake;
                snake = new SnakeMovement(*playfield_, levels.getSnakeLength());
                fruitCounter = 0;
            }
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
    time_t now = time(nullptr);
    int diff = (int)(now - lastUpdate);
    if (diff > 0) {
        timeDone += diff;
        lastUpdate = now;
    }

    // Check if time has run out
    if (timeDone >= timeTot) {
        gameOver = true;
        return;
    }

    stepResult res = snake->step();
    if (res == ate) {
        score += levels.getFruitBonus();
        timeTot += levels.getTimeBonus();
        fruitCounter++;
        if (fruitCounter >= 10 && levelBonus[levels.getLevel()] == false) {
            score += levels.getBonus();
            levelBonus[levels.getLevel()] = true;
            fruitCounter = 0;
        }
    }else if (res == game_over) {
        gameOver = true;
    }
    updateBuffer();
}
