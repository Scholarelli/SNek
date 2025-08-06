#include <ctime>
#include <cstdlib>

#include "SnakePlayfield.h"

SnakePlayfield::SnakePlayfield(int width, int height)
    : width(width), height(height), foodX(-1), foodY(-1), tiles(width * height, false) {}

void SnakePlayfield::resize(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
    tiles.resize(width * height, false); // Reset grid
}

void SnakePlayfield::update(const std::vector<bool>& newTiles) {
    if (newTiles.size() == tiles.size()) {
        tiles = newTiles;
    }
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

bool SnakePlayfield::isSnakeAt(int x, int y) const {
    return tiles[y * width + x]; // Check if tile contains part of the snake
}

bool SnakePlayfield::isFoodAt(int x, int y) const {
    return (foodX == x && foodY == y);
}

void SnakePlayfield::setSnakeTile(int x, int y) {
    tiles[y * width + x] = !tiles[y * width + x];
}