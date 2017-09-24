#ifndef ASTERIOD_H
#define ASTERIOD_H

#include "GameObject.h"
#include "Game.h"


class Asteriod : public GameObject
{
public:

    Asteriod(float angle);
    
//    float getCooldown() {
//        return _cooldown;
//    }
//    
//    void setCooldown(float newCooldown) {
//        _cooldown = newCooldown;
//    }
//    
//    void decrementAsteriodCooldown();
private:

//    float _cooldown;
    const float _SPEED_MULTIPLIER = 2.0f;
    
};

#endif