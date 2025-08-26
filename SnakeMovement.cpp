//
// Created by daniel on 8/6/25.
//
#include "SnakeMovement.h"
#include "UIAction.h"

SnakeMovement::SnakeMovement(SnakePlayfield& playfield_)
    : moveX(1), moveY(0), playfield(playfield_), snakeLength(4) {

    int X = playfield.getWidth() / 2;
    int Y = playfield.getHeight() / 2;

    snake[0] = {X, Y};
    snake[1] = {X-1, Y};
    snake[2] = {X-2, Y};
    snake[3] = {X-3, Y};

    playfield.clear();
    playfield.setSnakeTile(X, Y);
    playfield.setSnakeTile(X-1, Y);
    playfield.setSnakeTile(X-2, Y);
    playfield.setSnakeTile(X-3, Y);
    playfield.spawnFood();
}

void SnakeMovement::direction(int x, int y) {
    if (x == -moveX && y == -moveY) return; //inversione
    moveX = x;
    moveY = y;
}

void SnakeMovement::step() {
    int newX = (snake[0].x + moveX + playfield.getWidth()) % playfield.getWidth();
    int newY = (snake[0].y + moveY + playfield.getHeight()) % playfield.getHeight();

    //collisione, nuova pos è uguale a pezzo di snake
   for (int i = 0; i < snakeLength - 1; i++) {
       if (snake[i].x == newX && snake[i].y == newY) {
           return;
       }
   }
    //movimento
    for (int i = snakeLength - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }


    snake[0].x = newX;
    snake[0].y = newY;

    if (playfield.isFoodAt(newX, newY)) {
        playfield.spawnFood();
        snakeLength++;
        if (snakeLength > maxLength) {
            snakeLength = maxLength;
        }
    }

    playfield.clear();

    for (int i = 0; i < snakeLength; i++) {
        playfield.setSnakeTile(snake[i].x, snake[i].y);
    }

}

