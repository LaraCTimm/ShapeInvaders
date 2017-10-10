#ifndef LASER_GENERATOR_H
#define LASER_GENERATOR_H

#include "GameObject.h"
#include "Game.h"
//#include "ArcSegment.h"
/**
 * @class LaserGenerator - represents single laser generator in pair
 * Inherited from GameObject class 
 */
class LaserGenerator : public GameObject
{
public:
/**
 * @brief Laser generator constructor
 * @param degrees - angle at which generator is instantiated and along which it moves
 * @param ID - unique ID assigned to set of generators and arc segments
 */
LaserGenerator (float degrees, int ID);
/**
 * @brief Gets laser generator's ID unique to its set of generators and arc segments
 * @return Laser generator's ID
 */
int &getID() {
    return _ID;
}
/**
 * @brief gets number of arc segments between laser generator pairs
 * @return number of arc segments
 */
int getNumArcSegs() {
    return _NUM_ARC_SEGS;
}
/**
 * @brief Gets angle of separation between laser generator pair
 * @return angle of separation
 */
int getSeparationAngle() {
    return _SEPARATION_ANGLE;
}

private:

int _ID;
const int _NUM_ARC_SEGS = 7;
const int _SEPARATION_ANGLE = 8;

};

#endif