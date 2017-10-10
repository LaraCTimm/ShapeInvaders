#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include "GameObject.h"
#include "Game.h"
#include "Player.h"

class PlayerBullet : public GameObject
{
public:

    PlayerBullet(float xCoord, float yCoord, vector<float> pathVector, float angle);
    
private:
    
};

#endif