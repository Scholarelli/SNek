#ifndef SNAKEPLAYFIELD_H
#define SNAKEPLAYFIELD_H


class SnakePlayfield {
private:
    int width, height, foodX, foodY;
    bool* campo;

public:
    SnakePlayfield(int width, int height);
    ~SnakePlayfield();

    void resize(int newWidth, int newHeight);

    void spawnFood();

    bool isSnakeAt(int x, int y) const {
        return campo[y * width + x];
    };
    bool isFoodAt(int x, int y) const {
        return (foodX == x && foodY == y);
    };

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void setSnakeTile(int x, int y) {
        campo[y * width + x] = true;
    };
    void clear();
};

#endif // SNAKEPLAYFIELD_H