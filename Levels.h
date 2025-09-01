//
// Created by danielp on 8/28/25.
//

#ifndef SNEK_LEVELS_H
#define SNEK_LEVELS_H


class Levels {
private:
    struct Node {
        int level;
        int timeDone;
        int snakeLength;
        int snakeSpeed;
        int fruitBonus;
        int timeBonus;
        Node* next;
        Node* prev;
    };

    Node* root;
    Node* current;

public:
    Levels() : root(nullptr), current(nullptr) {}
    ~Levels();

    void addLevel(int l, int tD, int sL, int sS, int b, int tB);

    void nextLevel();
    void previousLevel();


    int getLevel() { return current ? current->level : 0; }
    int getTimeDone() { return current ? current->timeDone : 0; }
    int getSnakeLength() { return current ? current->snakeLength : 1; }
    int getSnakeSpeed() { return current ? current->snakeSpeed : 1; }
    int getFruitBonus() { return current ? current->fruitBonus : 0; }
    int getTimeBonus() { return current ? current->timeBonus : 0; }

    //void addTime();

};


#endif //SNEK_LEVELS_H