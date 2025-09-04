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
#include <ctime>

class GameWindow : public UiWindow {
private:
    SnakePlayfield* playfield_;
    DoubleBuffer* buffer_;
    SnakeMovement* snake;
    Levels levels;

    int score;
    time_t start;
    time_t lastUpdate;
    int timeTot;
    int timeDone;
    bool gameOver;
    bool levelBonus[8];
    int fruitCounter;
    bool paused;

    void updateBuffer() const;

public:
    GameWindow(int width, int height)
        : UiWindow(0, 0, width, height),
          score(0), timeTot(10), timeDone(0), gameOver(false), start(time(nullptr)), lastUpdate(time(nullptr)), paused(false), fruitCounter(0){
        for (int i = 0; i < 8; i++) {
            levelBonus[i] = false;
        }
        playfield_ = new SnakePlayfield(width -3 , height -3);
        buffer_ = new DoubleBuffer(width -3, height -3);
        snake = new SnakeMovement(*playfield_, levels.getSnakeLength());

        winPointer = newwin(height -1, width -1, 0, 0);
    }

    ~GameWindow() override {
        delete playfield_;
        delete buffer_;
        delete snake;
        clear();
        refresh();
    };


    void resize(int newWidth, int newHeight) override;


    void spawn() const;
    void draw();
    void render(WINDOW *win) override;
    void renderFull(WINDOW *win);
    UiAction handleInput(controls input) override;
    void initializeWindow(WINDOW *parent) override;
    void update();
    int getSpeed(){return levels.getSnakeSpeed();};
    bool isGameOver() const { return gameOver; };
    void pauseTimer();
    void resumeTimer();
    int getScore() const { return score; };
};



#endif //GAMEWINDOW_H
