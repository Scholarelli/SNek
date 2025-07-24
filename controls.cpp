#include "controls.h"

#include <ncurses.h>

controls get_user_input() {
    int c = getch();
    flushinp();
    switch (c) {
        case KEY_UP:    case 'w': return controls::MOVE_UP;
        case KEY_DOWN:  case 's': return controls::MOVE_DOWN;
        case KEY_LEFT:  case 'a': return controls::MOVE_LEFT;
        case KEY_RIGHT: case 'd': return controls::MOVE_RIGHT;
        case ' ': case 'p':                 return controls::PAUSE;
        case 'q':                 return controls::QUIT;
        default:                  return controls::PAUSE;
    }
}