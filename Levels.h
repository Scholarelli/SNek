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
        int bonus;
        Node* next;
        Node* prev;
    };

    Node* root;
    Node* current;

public:
    Levels() : root(nullptr), current(nullptr) {
        addLevel(1, 0, 5, 2, 5, 25, 15);
        addLevel(2, 0, 8, 4, 10, 22, 30);
        addLevel(3, 0, 15, 6, 15, 20, 45);
        addLevel(4, 0, 25, 8, 20, 18, 60);
        addLevel(5, 0, 32, 10, 50, 13, 75);
        addLevel(6, 0, 40, 20, 100, 10, 90);
        addLevel(7, 0, 50, 25, 500, 7, 105);
    }
    ~Levels();

    void addLevel(int l, int tD, int sL, int sS, int b, int tB, int B);

    bool nextLevel();

    bool previousLevel();


    int getLevel() { return current ? current->level : 0; }
    int getTimeDone() { return current ? current->timeDone : 0; }
    int getSnakeLength() { return current ? current->snakeLength : 1; }
    int getSnakeSpeed() { return current ? current->snakeSpeed : 1; }
    int getFruitBonus() { return current ? current->fruitBonus : 0; }
    int getTimeBonus() { return current ? current->timeBonus : 0; }
    int getBonus() { return current ? current->bonus : 0; }

    //void addTime();

};


#endif //SNEK_LEVELS_H