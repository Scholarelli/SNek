//
// Created by Emanuele Cianfanelli on 14/03/25.
//

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "SnakePlayfield.h"

#include "Buffer.h"
#include "DoubleBuffer.h"

class GameWindow {
private:
    int width, height;
    std::unique_ptr<SnakePlayfield> playfield_;
    std::unique_ptr<DoubleBuffer> buffer_;

    void updateBuffer() const;
public:
    GameWindow(int width, int height)
        : width(width), height(height),
          playfield_(std::make_unique<SnakePlayfield>(width, height)),
          buffer_(std::make_unique<DoubleBuffer>(width, height)) {
    }

    void setTile(int x, int y) const;
    void resize(int x, int y);

    static void initialize();
    void spawn() const;
    void draw();
    void render(WINDOW *win) const;

};



#endif //GAMEWINDOW_H
