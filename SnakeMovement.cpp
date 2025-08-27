//
// Created by daniel on 8/6/25.
//
#include "SnakeMovement.h"
#include "UIAction.h"

SnakeMovement::SnakeMovement(SnakePlayfield& playfield_)
    : moveX(1), moveY(0), playfield(playfield_), snakeLength(5) {

    int X = playfield.getWidth() / 2;
    int Y = playfield.getHeight() / 2;

    for (int i = 0; i < snakeLength; i++) {
        snake[i] = {X-i, Y};

    }

    playfield.clear();
    for (int i = 0; i < snakeLength; i++) {
        playfield.toggleSnakeTile(X-i, Y);
    }
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

    // Togliamo la coda prima di muoverci
   bool growing = playfield.isFoodAt(newX, newY);
    if (/*!growing && */snakeLength > 0) {
        int tailX = snake[snakeLength - 1].x;
        int tailY = snake[snakeLength - 1].y;
        playfield.toggleSnakeTile(tailX, tailY);
    }

    for (int i = snakeLength - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    snake[0].x = newX;
    snake[0].y = newY;

    playfield.toggleSnakeTile(newX, newY);

    if (growing) {
        playfield.spawnFood();
        //snakeLength++;
        // if (snakeLength > maxLength) {
        //     snakeLength = maxLength;
        // }
    }

}
