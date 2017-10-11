#ifndef ASTERIOD_H
#define ASTERIOD_H

#include "GameObject.h"
#include "Game.h"

/**
 * @class Asteriod - represents enemy asteroid 
 * Inherited from GameObject class
 */
class Asteriod : public GameObject
{
public:
/** 
 * @brief Asteroid contructor
 * @param Angle at which asteroid is instantiated & along which it moves
 */ 
    Asteriod(float angle);
    
private:

    const float _SPEED_MULTIPLIER = 2.0f;
    
};

#endif