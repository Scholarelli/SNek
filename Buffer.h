#ifndef BUFFER_H
#define BUFFER_H
#include <vector>
#include <ncurses.h>

struct Tile {
    char ch = ' ';
    int color = 0;
    bool bold = false;

    bool operator==(const Tile &other) const {
        return ch == other.ch
               && color == other.color
               && bold == other.bold;
    }

    bool operator!=(const Tile &other) const {
        return !(*this == other);
    }
};

class Buffer {
private:
    int width, height;
    std::vector<Tile> grid;

    int index(int x, int y) const {
        return y * width + x;
    }
public:
    Buffer(int w, int h) : width(w), height(h), grid((w * h), {' ', 0, false}) {}

    ~Buffer() = default;

    const Tile& operator()(const int x, const int y) const { return grid[index(x, y)]; }
    Tile &operator()(const int x, const int y) { return grid[index(x, y)]; }

    void setTile(int x, int y, char ch, int color = 0, bool bold = false);
    Tile getTile(int x, int y) const;
    void render(WINDOW *win, const Buffer& prevBuffer, bool renderAll) const;

    void clear();

    int getWidth() const;
    int getHeight() const;

    void resize(int x, int y);
};


#endif //BUFFER_H
