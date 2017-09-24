#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Game.h"

class Enemy : public GameObject
{
public:

    Enemy(float xCoord, float yCoord, float angle);

//    void decrementEnemyCooldown();
    
    void decrementEnemyBulletCooldown();
    
    //////////////////////////
    
//    float getCooldown() {
//        return _cooldown;
//    }
//    
//    void setCooldown(float newCooldown) {
//        _cooldown = newCooldown;
//    }
    
    float getBulletCooldown() {
        return _bulletCooldown;
    }
    
    void setBulletCooldown(float newBulletCooldown) {
        _bulletCooldown = newBulletCooldown;
    }

private:

    //float _cooldown;
    float _bulletCooldown;
    
};

#endif