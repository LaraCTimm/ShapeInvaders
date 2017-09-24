#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include "GameObject.h"
#include "Game.h"
#include "Player.h"

class PlayerBullet : public GameObject
{
public:

    PlayerBullet(float xCoord, float yCoord, sf::Vector2f pathVector, float angle);
    
private:
    
};

#endif