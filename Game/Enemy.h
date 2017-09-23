#ifndef ENEMY_H
#define ENEMY_H

#include "Game.h"
#include "GameObject.h"
#include <iostream>
using std::cout;
using std::endl;


class Enemy : public GameObject
{
public:

    Enemy(float xCoord, float yCoord, float angle);
    
private:
    
};

#endif