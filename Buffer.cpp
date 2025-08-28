#include "Buffer.h"
#include <curses.h>

void Buffer::setTile(int x, int y, char ch, int color, bool bold) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        (*this)(x, y) = {ch, color, bold};
    }
}

Tile Buffer::getTile(int x, int y) const {
    return (* this)(x, y);
}


void Buffer::render(WINDOW *win, const Buffer &prevBuffer, bool renderAll) const {
    box(win, 0, 0);
    for (int i = 0; i < width * height; i++) {
        if (renderAll || grid[i] != prevBuffer.grid[i]) {
            const int x = i % width + 1;
            const int y = i / width + 1;
            const auto&[ch, color, bold] = grid[i];

            attr_t attributes = COLOR_PAIR(color);
            if (bold) {
                attributes |= A_BOLD;
            }

            wattr_on(win, attributes, nullptr);
            mvwaddch(win, y, x, ch);
            wattr_off(win, attributes, nullptr);
        }
    }
    wnoutrefresh(win);
}

void Buffer::clear() {
    std::fill(grid.begin(), grid.end(), Tile{' ', 0, false});
}

int Buffer::getHeight() const {
    return height;
}

int Buffer::getWidth() const {
    return width;
}

void Buffer::resize(int x, int y) {
    this->width = x;
    this->height = y;

    grid.resize(width * height, Tile{});
    clear();
}
