#pragma once
#include "C:\raylib\raylib\src\raylib.h"

class Block {
    public:
        Block(Vector2 position);
        void Draw();
        Rectangle getRect();
    private:
        Vector2 position;
};