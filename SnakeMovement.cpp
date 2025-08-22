//
// Created by daniel on 8/6/25.
//
#include "SnakeMovement.h"


SnakeMovement::SnakeMovement(int width, int height, SnakePlayfield& playfield_)
    : width(width), height(height), moveX(1), moveY(0), playfield(playfield_) {

    int X = width / 2;
    int Y = height / 2;
    snake.push_front({X, Y});
    playfield.setSnakeTile(X, Y);
    playfield.spawnFood();
}

void SnakeMovement::direction(int x, int y) {
    if (x == -moveX && y == -moveY) return; //inversione
    moveX = x;
    moveY = y;
}

void SnakeMovement::step() {
    std::pair<int, int> currentPos = snake.front();

    int newX = (currentPos.first + moveX + width) % width;
    int newY = (currentPos.second + moveY + height) % height;

    for (auto & i : snake) {
        if (newX == i.first && newY == i.second) {
            return; // collisione
        }
    }

    snake.push_front({newX, newY});

    if (playfield.isFoodAt(newX, newY)) {
        playfield.spawnFood();
    }else {
        snake.pop_back();
    }

    playfield.update(std::vector<bool>(width * height, false));//aggiorno il campo a false
    //for (const std::pair<int, int> pixel: snake) {
    //    playfield.setSnakeTile(pixel.first, pixel.second);
    //}
    for (auto & i : snake) {
        playfield.setSnakeTile(i.first, i.second);
    }

}

std::deque<std::pair<int, int>> SnakeMovement::getSnake() {
    return snake;
}

