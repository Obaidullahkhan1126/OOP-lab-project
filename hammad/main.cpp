#include "raylib.h"
//#include "game.hpp"
#include "Aliens.hpp"

int main(){
    Color grey = {29,29,27,255};
    int windowwidth = 750;
    int windowHeight = 700;

    //Initwindow(windowWidth,WindowHeight,"C++ Space Invaders");
    //SetTargetFPS(60);

    Game game;
    Alien alien = Alien(1{100,100});

    while (WindowShouldClose()==false){
        game.HandleInput();
        game.Update()
        BeginDrawing();
        ClearBackgorund(grey);
        game.Draw();
        
        EndDrawing();
    }

    CloseWindow();


}
