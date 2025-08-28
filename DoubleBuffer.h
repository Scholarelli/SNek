#ifndef DOUBLEBUFFER_H
#define DOUBLEBUFFER_H
#include "Buffer.h"


class DoubleBuffer {
private:
    Buffer *frontBuffer;
    Buffer *backBuffer;

    void swapBuffer();
public:
    DoubleBuffer(int w, int h) : frontBuffer(new Buffer(w, h)), backBuffer(new Buffer(w, h)) {}

    ~DoubleBuffer() {
        delete frontBuffer;
        delete backBuffer;
    }
    void setTile(int x, int y, char ch, int color = 0, bool bold = false) const;
    void resize(int x, int y);
    void render(WINDOW *win, bool renderAll = false);


};

#endif //DOUBLEBUFFER_H
