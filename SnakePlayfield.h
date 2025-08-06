#ifndef SNAKEPLAYFIELD_H
#define SNAKEPLAYFIELD_H

#include <vector>

class SnakePlayfield {
private:
    int width, height, foodX, foodY;
    std::vector<bool> tiles; // Represents snake presence on the grid

public:
    SnakePlayfield(int width, int height);

    void resize(int newWidth, int newHeight);
    void update(const std::vector<bool>& newTiles);

    void spawnFood();

    bool isSnakeAt(int x, int y) const;
    bool isFoodAt(int x, int y) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void setSnakeTile(int x, int y);
};

#endif // SNAKEPLAYFIELD_H