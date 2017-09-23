#ifndef ASTERIOD_H
#define ASTERIOD_H

#include "GameObject.h"

class Asteriod : public GameObject
{
public:

    Asteriod(float xCoord, float yCoord, float angle);
    
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

    float _cooldown;
    
};

#endif