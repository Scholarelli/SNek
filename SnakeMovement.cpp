//
// Created by daniel on 8/6/25.
//
#include "SnakeMovement.h"

SnakeMovement::SnakeMovement(int width, int height)
    : width(width), height(height), moveX(1), moveY(0) {

    int startX = width / 2;
    int startY = height / 2;
    snake.push_front({startX, startY});
}

void SnakeMovement::direction(int x, int y) {
    if (x == -moveX && y == -moveY) return; //inversione
    moveX = x;
    moveY = y;
}

void SnakeMovement::step() {
    std::pair<int, int> currentPos = snake.front();

    int newX = currentPos.first + moveX;
    int newY = currentPos.second + moveY;

    snake.push_front({newX, newY});

    if (!food) {
        snake.pop_back();
    }
    food = false;
}

void SnakeMovement::grow() {
    food = true;
}

std::deque<std::pair<int, int>> SnakeMovement::getSnake() {
    return snake;
}

