#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "GameObject.h"
#include "Game.h"
#include "Enemy.h"

class EnemyBullet : public GameObject
{
public:

    EnemyBullet(float xCoord, float yCoord, vector<float> pathVector, float angle, int scaleCount);
    
    
private:

    
};

#endif