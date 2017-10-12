#include "ArcSegment.h"

ArcSegment::ArcSegment(float angle, int ID) : GameObject()
{
    _xCoord = Game::ORIGIN_X;
	_yCoord = Game::ORIGIN_Y;
    _angle = angle;
    _ID = ID;
    _objectWidth = 7;
    _objectHeight = 40;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _health = 1;
    _points = 10;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / 275;
    _scaleCount = 0;
    _objectType = gameObjectType::ArcSegment;
    _shapeProperties = {3.0, 255, 255, 50};

    
    float vecX = cos(_angle*(M_PI/180));
    float vecY = sin(_angle*(M_PI/180));

    _xCoord += 2*vecX;
	_yCoord += 2*vecY;
    
    _pathVector[0] = vecX;
    _pathVector[1] = vecY;

}