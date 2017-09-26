#ifndef LASER_GENERATOR_H
#define LASER_GENERATOR_H

#include "GameObject.h"
#include "Game.h"
//#include "ArcSegment.h"

class LaserGenerator : public GameObject
{
public:

LaserGenerator (float degrees, int ID);

int &getID() {
    return _ID;
}

int getNumArcSegs() {
    return _NUM_ARC_SEGS;
}

int getSeparationAngle() {
    return _SEPARATION_ANGLE;
}

private:

int _ID;
const int _NUM_ARC_SEGS = 7;
const int _SEPARATION_ANGLE = 8;

};

#endif