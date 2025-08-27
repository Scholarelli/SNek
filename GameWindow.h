//
// Created by Emanuele Cianfanelli on 14/03/25.
//

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "SnakePlayfield.h"

#include "Buffer.h"
#include "DoubleBuffer.h"
#include "UiWindow.h"
#include <memory>

#include "SnakeMovement.h"

class GameWindow : public UiWindow {
private:
    std::unique_ptr<SnakePlayfield> playfield_;
    std::unique_ptr<DoubleBuffer> buffer_;
    std::unique_ptr<SnakeMovement> snake;
    void updateBuffer() const;

public:
    GameWindow(int width, int height)
        : UiWindow(0, 0, width, height),
          playfield_(std::make_unique<SnakePlayfield>(width -3 , height -3)),
          buffer_(std::make_unique<DoubleBuffer>(width -3, height -3)),
          snake(std::make_unique<SnakeMovement> (*playfield_) ){

        winPointer = newwin(height -1, width -1, 0, 0);
    }

    ~GameWindow() override {
        clear();
        refresh();
    };

   // void setTile(int x, int y) const;
    void resize(int newWidth, int newHeight) override;


    void spawn() const;
    void draw();
    void render(WINDOW *win) override;
    UiAction handleInput(controls input) override;
    void initializeWindow(WINDOW *parent) override;
    void update();

};



#endif //GAMEWINDOW_H
