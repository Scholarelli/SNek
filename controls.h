
#ifndef CONTROLS_H
#define CONTROLS_H
enum controls {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_ENTER,
    PAUSE,
    QUIT,
    NO_INPUT,
    RESIZE,
    FREEZE
};


controls get_user_input();
#endif //CONTROLS_H
