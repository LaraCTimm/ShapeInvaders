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
	 * @param pathVector - vector along which bullet is to move
	 * @param angle - angle at which bullet is to be instantiated and along which it moves
	 * @param scaleCount - ~~~~~Pls help, La~~~~~~~~~~~~
	 */
	EnemyBullet(float xCoord, float yCoord, vector<float> pathVector, float angle, int scaleCount);
    
//    float getCooldown(float newCooldown) {
//        return _cooldown;
//    }
//    
//    void setCooldown(float newCooldown) {
//        _cooldown = newCooldown;
//    }
//    
//    void decrementEnemyBulletCooldown();
    
private:

//    float _cooldown;
    
};

#endif