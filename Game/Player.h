#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Game.h"

/**
* Player class - represents the Player.
* Inherits from GameObject class.
*/

class Player : public GameObject
{
public:

    Player();
    
private:

    const float _BULLET_OFFSET_X = -15;
    const float _BULLET_OFFSET_Y = 0;
    
};

#endif