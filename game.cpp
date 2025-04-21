#include "game.hpp"
#include <iostream>
#include <fstream>
using namespace std;
Game::Game()
{
    music = LoadMusicStream("Sounds/music.ogg");
    explosionSound = LoadSound("Sounds/explosion.ogg");
    PlayMusicStream(music);
    InitGame();
}

Game::~Game() {
    Alien::UnloadImages();
    UnloadMusicStream(music);
    UnloadSound(explosionSound);
}

void Game::Update() {
    if(run) {

        double currentTime = GetTime();
        if(currentTime - timeLastSpawn > mysteryShipSpawnInterval) {
            mysteryship.Spawn();
            timeLastSpawn = GetTime();
            mysteryShipSpawnInterval = GetRandomValue(10, 20);
        }

        for(auto& laser: spaceship.lasers) {
            laser.Update();
        }

        MoveAliens();

        AlienShootLaser();

        for(auto& laser: alienLasers) {
            laser.Update();
        }

        DeleteInactiveLasers();
        
        mysteryship.Update();

        CheckForCollisions();
    } else {
        if(IsKeyDown(KEY_ENTER)){
            Reset();
            InitGame();
        }
    }
}

void Game::Draw() {
    spaceship.Draw();

    for(auto& laser: spaceship.lasers) {
        laser.Draw();
    }

    for(auto& obstacle: obstacles) {
        obstacle.Draw();
    }

    for(auto& alien: aliens) {
        alien.Draw();
    }

    for(auto& laser: alienLasers) {
        laser.Draw();
    }

    mysteryship.Draw();
}

void Game::HandleInput() {
    if(run){
        if(IsKeyDown(KEY_LEFT)) {
            spaceship.MoveLeft();
        } else if (IsKeyDown(KEY_RIGHT)){
            spaceship.MoveRight();
        } else if (IsKeyDown(KEY_SPACE)) {
            spaceship.FireLaser();
        }
    }
}

void Game::DeleteInactiveLasers()
{
    for(auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();){
        if(!it -> active) {
            it = spaceship.lasers.erase(it);
        } else {
            ++ it;
        }
    }

    for(auto it = alienLasers.begin(); it != alienLasers.end();){
        if(!it -> active) {
            it = alienLasers.erase(it);
        } else {
            ++ it;
        }
    }
}

std::vector<Obstacle> Game::CreateObstacles()
{
    int obstacleWidth = Obstacle::grid[0].size() * 3;
    float gap = (GetScreenWidth() - (4 * obstacleWidth))/5;

    for(int i = 0; i < 4; i++) {
        float offsetX = (i + 1) * gap + i * obstacleWidth;
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 200)}));
    }
    return obstacles;
}
std::vector<Aliens>Game::CreateAliens(){
    std::vector<Alien>aliens;
    for(int row=0;row<5;row++){
        for(int column=0;column<11;column++){
            int alientype;
            if(row ==0){
                alientype =3;
            }
            else if(row==1||row==2){
                alientype = 2;
            }
                else{
                    alientype = 1;
                }
            
            float x = 75 + column*55;// cell size = 55px
            float y = 110 + row*55;// cellsize = 55 px
            aliens.push_back(Alien(alientype,{x,y}));
        }
    }
    return  aliens;
}
void  Game::MoveAliens(){
    for(auto& alien: aliens){
        if(alien.position.x + alien.alienImages[alien.type-1].width>GetScreenWidth())
        {
            aliensDirection = -1; 
            MoveDownAliens(4);
        }
        if(alien.position.x<0){
            MoveDownAliens(4);
            aliensDirection = 1;
        }
        alien.Update(aliensDirection);
    }
}
void Game::MoveDownAliens(int distance){
    for(auto& alien : aliens){
        alien.position.y += distance;
    }
}
void Game::AlienShootLaser()
{
int randomIndex = GetRandomValue(0,aliens.size()-1);
Alien& alien = aliens[randomIndex];
alienLasers.push_back(Laser({alien.position.x+alien.alienImages[alien.type-1].width/2,alien.position.y+alien.alienImages[alien.type-1].height},6));

}