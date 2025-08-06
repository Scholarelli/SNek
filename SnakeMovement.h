//
// Created by daniel on 8/5/25.
//

#ifndef SNAKEMOVEMENT_H
#define SNAKEMOVEMENT_H

#include <deque>
#include <utility>


class SnakeMovement {
private:

    int width, height, moveX, moveY;
    std::deque<std::pair<int, int>> snake;
    bool food = false;

public:

    SnakeMovement(int width, int height);

    std::deque<std::pair<int, int>> getSnake();
    void direction(int x, int y);
    void step();
    void grow();

};

#endif //SNAKEMOVEMENT_H
