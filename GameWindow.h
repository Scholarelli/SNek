//
// Created by Emanuele Cianfanelli on 14/03/25.
//

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "SnakePlayfield.h"

#include "Buffer.h"
#include "DoubleBuffer.h"
#include "UiWindow.h"

class GameWindow : public UiWindow {
private:
    std::unique_ptr<SnakePlayfield> playfield_;
    std::unique_ptr<DoubleBuffer> buffer_;

    void updateBuffer() const;
public:
    GameWindow(int width, int height)
        : UiWindow(0, 0, width, height),
          playfield_(std::make_unique<SnakePlayfield>(width, height)),
          buffer_(std::make_unique<DoubleBuffer>(width, height)) {
    }

    void setTile(int x, int y) const;
    void resize(int newWidth, int newHeight) override;


    void spawn() const;
    void draw();
    void render(WINDOW *win) override;
    UiAction handleInput(controls input) override;
    void initializeWindow(WINDOW *parent) override;

};



#endif //GAMEWINDOW_H
