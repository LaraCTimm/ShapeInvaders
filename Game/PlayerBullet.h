#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "GameObject.h"
#include "Game.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class PlayerBullet : public GameObject
{
public:

    PlayerBullet(float xCoord, float yCoord, sf::Vector2f pathVector, float angle);
    
private:
    
};

#endif