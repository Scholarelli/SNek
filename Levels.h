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
    Levels() : root(nullptr), current(nullptr) {
        addLevel(1, 0, 5, 2, 5, 25);
        addLevel(2, 0, 8, 4, 10, 22);
        addLevel(3, 0, 10, 6, 15, 20);
        addLevel(4, 0, 15, 8, 20, 18);
        addLevel(5, 0, 20, 10, 50, 13);
        addLevel(6, 0, 30, 20, 100, 10);
        addLevel(7, 0, 50, 40, 500, 7);
    }
    ~Levels();

    void addLevel(int l, int tD, int sL, int sS, int b, int tB);

    bool nextLevel();

    bool previousLevel();


    int getLevel() { return current ? current->level : 0; }
    int getTimeDone() { return current ? current->timeDone : 0; }
    int getSnakeLength() { return current ? current->snakeLength : 1; }
    int getSnakeSpeed() { return current ? current->snakeSpeed : 1; }
    int getFruitBonus() { return current ? current->fruitBonus : 0; }
    int getTimeBonus() { return current ? current->timeBonus : 0; }

    //void addTime();

};


#endif //SNEK_LEVELS_H