#pragma once
//#include "Spaceship.hpp"
//#include "obstacle.hpp"
#include "alien.hpp"
using namespace std;


class Game{
    public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
    private:
    void DeleteInactiveLasers();
    vector<Obstacle>CreateObstacles();
    vector<Alien>CreateAliens();
    void MoveAliens();
    void MoveDownAliens(int distance);
    void AlienShootLaser()
    Spaceship spaceship;
    vector<Obstacle>obstacles;
    vector<Alien>aliens;
    int aliensDirection;
    vector<Laser>alienLasers;
    constexpr stattic alienLasersShootInterval = 0.35;
    float timeLastAlienFired;    
};

