
#include "DoubleBuffer.h"


void DoubleBuffer::setTile(int x, int y, char ch, int color, bool bold) const {
    backBuffer->setTile(x, y, ch, color, bold);
}

void DoubleBuffer::swapBuffer() {
    std::swap(frontBuffer, backBuffer);
}


void DoubleBuffer::render(WINDOW *win, bool renderAll) {
    backBuffer->render(win, *frontBuffer, renderAll);
    swapBuffer();
}

void DoubleBuffer::resize(int x, int y) {
    frontBuffer->resize(x, y);
    backBuffer->resize(x, y);

}
