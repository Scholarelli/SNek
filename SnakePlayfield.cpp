#include <ctime>
#include <cstdlib>

#include "SnakePlayfield.h"

SnakePlayfield::SnakePlayfield(int width, int height)
    : width(width), height(height), foodX(-1), foodY(-1){
    campo = new bool[width * height];
    clear();
}


SnakePlayfield::~SnakePlayfield() {
    delete[] campo;
}


void SnakePlayfield::resize(int newWidth, int newHeight) {
    delete[] campo;
    width = newWidth;
    height = newHeight;
    campo = new bool[width * height];
    clear();
}


void SnakePlayfield::spawnFood() {
    int x, y;
    do {
        x = std::rand() % width;
        y = std::rand() % height;
    }while (isSnakeAt(x, y));

    foodX = x;
    foodY = y;
}

void SnakePlayfield::clear() {
    for (int i = 0; i < width * height; i++) {
        campo[i] = false;
    }
}