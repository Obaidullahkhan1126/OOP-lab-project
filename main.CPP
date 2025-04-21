#include<raylib.h>
#include "game.hpp"
#include"alien.hpp"
int main(){
    Color grey = {29,29,27,255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth,windowHeight,"C++ Space Invaders");
    SetTargetFPS(60);
    Game game;
    Alien alien = Alien(1,(100,100));

    while (WindowShouldClose()==false){
        game.Handleinput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        game.Draw();
        alien.Draw();
        EndDrawing();
    }
    CloseWindow();
}