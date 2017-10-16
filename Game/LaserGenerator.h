#ifndef LASER_GENERATOR_H
#define LASER_GENERATOR_H

#include "GameObject.h"
#include "Game.h"

/**
 * @class LaserGenerator
 * @brief Represents single laser generator in pair.
 * 
 * Inherited from GameObject class.
 */
class LaserGenerator : public GameObject
{
public:

    static constexpr int NUM_ARC_SEGS = 7;
    static constexpr int SEPARATION_ANGLE = 8;
    
/**
 * @brief Laser generator constructor.
 * @param degrees - angle at which generator is instantiated and along which it moves.
 * @param ID - unique ID assigned to set of generators and arc segments.
 */
LaserGenerator (float degrees, int ID);
/**
 * @brief Gets laser generator's ID unique to its set of generators and arc segments.
 * @return Laser generator's ID.
 */
int getID() {
    return _ID;
}

private:

int _ID;

};

#endif