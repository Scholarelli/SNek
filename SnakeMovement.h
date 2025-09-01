    //
    // Created by daniel on 8/5/25.
    //

    #ifndef SNAKEMOVEMENT_H
    #define SNAKEMOVEMENT_H


    #include "SnakePlayfield.h"

    struct XYposition {
        int x, y;
    };

    class SnakeMovement {
    private:

        int moveX, moveY;
        static const int maxLength = 500;
        int snakeLength;
        XYposition snake[maxLength];
        SnakePlayfield& playfield;

    public:

        SnakeMovement(SnakePlayfield& playfield, int levelLength);
        void direction(int x, int y);
        void step();
        XYposition getHead() {return snake[0];};

    };

    #endif //SNAKEMOVEMENT_H
