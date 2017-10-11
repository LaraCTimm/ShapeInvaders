#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "GameObject.h"
#include "Game.h"
#include "Enemy.h"

/**
 * @class EnemyBullet - represents bullets shot by enemy
 * Inherits from GameObject class
 */
class EnemyBullet : public GameObject
{
public:

	/** 
	 * @brief Enemy bullet constructor
	 * @param xCoord - x-coordinate at which bullet is to be instantiated
	 * @param yCoord - y-coordinate at which bullet is to be instantiated
	 * @param pathVector - vector along which bullet is to move. Set by respective Enemy object
	 * @param angle - angle at which bullet is to be instantiated and along which it moves
	 * @param scaleCount - enables the bullet to be spawned at the correct scale depending on how far along the vector the Enemy is.
	 */
	EnemyBullet(float xCoord, float yCoord, vector<float> pathVector, float angle, int scaleCount);
    
private: 

    const float SPEED_MULTIPLIER = 2.0f;

};

#endif