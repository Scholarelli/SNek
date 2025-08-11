//
// Created by daniel on 8/5/25.
//

#ifndef SNAKEMOVEMENT_H
#define SNAKEMOVEMENT_H

#include "SnakePlayfield.h"

#include <deque>
#include <utility>


class SnakeMovement {
private:

    int width, height, moveX, moveY;
    std::deque<std::pair<int, int>> snake;

    SnakePlayfield& playfield;

public:

    SnakeMovement(int width, int height, SnakePlayfield& playfield);

    std::deque<std::pair<int, int>> getSnake();
    void direction(int x, int y);
    void step();

};

#endif //SNAKEMOVEMENT_H
