    //
    // Created by daniel on 8/5/25.
    //

    #ifndef SNAKEMOVEMENT_H
    #define SNAKEMOVEMENT_H

   // #include <deque>
    //#include <utility>

    #include "SnakePlayfield.h"
    struct XYposition {
        int x, y;
    };

    class SnakeMovement {
    private:

        int width, height, moveX, moveY;
        //std::deque<std::pair<int, int>> snake;
        static const int maxLength = 500;
        int snakeLength;
        XYposition snake[maxLength];
        SnakePlayfield& playfield;

    public:

        SnakeMovement(int width, int height, SnakePlayfield& playfield);

        //std::deque<std::pair<int, int>> getSnake();
        void direction(int x, int y);
        void step();
        int getLength() {
            return snakeLength;
        }
        XYposition getSnake(int x, int y);

    };

    #endif //SNAKEMOVEMENT_H
