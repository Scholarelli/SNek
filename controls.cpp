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
        case KEY_RESIZE: return controls::RESIZE;
        case ' ': case 'p': case 10:  return controls::PAUSE;
        case 'f': return controls::FREEZE;
        case 'q':                 return controls::QUIT;
        case 'v': return controls::LEVEL_UP;
        case 'c': return controls::LEVEL_DOWN;
        default:                  return controls::NO_INPUT;
    }
}