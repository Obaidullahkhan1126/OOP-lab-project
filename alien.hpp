// Space Invaders 

// Aliens 
#pragma once
#include <raylib.h>
 

class Alien{
    public:
    Alien(int type, Vector2 position){}
    void Update(int direction);
    int Draw();
    int Gettype();
    static void UnloadImages();
    static Texture2D alienImages[3];
    int type;
    Vector2 position;

    private:

};
