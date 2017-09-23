#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "GameObject.h"

class PlayerBullet : public GameObject
{
public:

    PlayerBullet(float xCoord, float yCoord, sf::Vector2f pathVector, float angle);
    
private:
    
};

#endif