#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include "GameObject.h"
#include "Game.h"
#include "Player.h"

/**
 * @class PlayerBullet
 * @brief Represents the bullet belonging to the player
 * 
 * Inherited from the GameObject Class.
 */

class PlayerBullet : public GameObject
{
public:

    PlayerBullet(float xCoord, float yCoord, vector<float> pathVector, float angle);
    
private:
    
};

#endif