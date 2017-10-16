#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Game.h"

/**
 * @class Enemy
 * @brief Represents main enemy
 * 
 * Inherits from GameObject class
 */
class Enemy : public GameObject
{
public:
	/**
	 * @brief Enemy constructor
	 * @param xCoord - x-coordinate at which enemy is instantiated
	 * @param yCoord - y-coordinate at which enemy is instantiated
	 * @param angle - angle at which enemy is instantiated & along which it moves
	 */
	Enemy(float xCoord, float yCoord, float angle);

    /**
     * @brief Decrements enemy bullet cooldown if non-zero
     */
    void decrementEnemyBulletCooldown();

    /**
     * @brief Function which gets the bullet cooldown
     * @return Bullet cooldown 
     */
    float getBulletCooldown() {
        return _bulletCooldown;
    }
    
    /**
     * @brief Assigns new bullet cooldown to cooldown variable
     * @param newBulletCooldown - new value to be assigned to bullet cooldown variable
     */
    void setBulletCooldown(float newBulletCooldown) {
        _bulletCooldown = newBulletCooldown;
    }

private:

    float _bulletCooldown;
    
};

#endif