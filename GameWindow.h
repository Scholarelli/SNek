//
// Created by Emanuele Cianfanelli on 14/03/25.
//

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "SnakePlayfield.h"
#include "Buffer.h"
#include "DoubleBuffer.h"
#include "UiWindow.h"
#include "SnakeMovement.h"
#include "Levels.h"
#include <memory>
#include <ctime>

class GameWindow : public UiWindow {
private:
    std::unique_ptr<SnakePlayfield> playfield_;
    std::unique_ptr<DoubleBuffer> buffer_;
    std::unique_ptr<SnakeMovement> snake;
    Levels levels;

    int score;
    time_t start;
    time_t lastUpdate;
    int timeTot;
    int timeDone;

    void updateBuffer() const;

public:
    GameWindow(int width, int height)
        : UiWindow(0, 0, width, height),
          playfield_(std::make_unique<SnakePlayfield>(width -3 , height -3)),
          buffer_(std::make_unique<DoubleBuffer>(width -3, height -3)),
          score(0), timeTot(300), timeDone(0), start(time(nullptr)), lastUpdate(time(nullptr)) {

        snake = std::make_unique<SnakeMovement>(*playfield_, levels.getSnakeLength());

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
    void renderFull(WINDOW *win);
    UiAction handleInput(controls input) override;
    void initializeWindow(WINDOW *parent) override;
    void update();
    int getSpeed(){return levels.getSnakeSpeed();};
};



#endif //GAMEWINDOW_H
