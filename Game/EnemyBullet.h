#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "GameObject.h"

class EnemyBullet : public GameObject
{
public:

    EnemyBullet(float xCoord, float yCoord, sf::Vector2f pathVector, float angle, int scaleCount);
    
private:
    
};

#endif