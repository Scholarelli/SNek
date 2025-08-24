//
// Created by daniel on 8/6/25.
//
#include "SnakeMovement.h"
#include <cstdlib>

#include "UIAction.h"

SnakeMovement::SnakeMovement(int width, int height, SnakePlayfield& playfield_)
    : width(width), height(height), moveX(1), moveY(0), playfield(playfield_), snakeLength(1) {

    int X = width / 2;
    int Y = height / 2;
    snake[0] = {X, Y};
    playfield.setSnakeTile(X, Y);
    playfield.spawnFood();
}

void SnakeMovement::direction(int x, int y) {
    if (x == -moveX && y == -moveY) return; //inversione
    moveX = x;
    moveY = y;
}

void SnakeMovement::step() {

    int newX = (snake[0].x + moveX + width) % width;
    int newY = (snake[0].y + moveY + height) % height;

    //collisione, nuova pos è uguale a pezzo di snake
   for (int i = 0; i < snakeLength; i++) {
       if (snake[i].x == newX && snake[i].y == newY) {
           UI_GAME_OVER;
           return;
       }
   }
    snake[0].x = newX;
    snake[0].y = newY;

    //movimento
    for (int i = 1; i < snakeLength; i++) {
        snake[i] = snake[i - 1];
    }

    if (playfield.isFoodAt(newX, newY)) {
        playfield.spawnFood();
        snakeLength++;
    }

    playfield.update(std::vector<bool>(width * height, false));//aggiorno il campo a false

    for (int i = 0; i < snakeLength; i++) {
        playfield.setSnakeTile(snake[i].x, snake[i].y);
    }

}

