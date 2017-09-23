#ifndef ARC_SEGMENT_H
#define ARC_SEGMENT_H

#include "GameObject.h"
//#include "Game.h"
#include <SFML/Graphics.hpp>

class ArcSegment : public GameObject
{
public:

ArcSegment(float angle, int ID);

int getID() { return _ID; };

private:

int _ID;

};

#endif