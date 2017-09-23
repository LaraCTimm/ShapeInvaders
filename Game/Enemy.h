#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject
{
public:

    Enemy(float xCoord, float yCoord, sf::Vector2f pathVector, float angle);
    
private:
    
};

#endif