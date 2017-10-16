#include "Asteriod.h"

Asteriod::Asteriod(float angle) : GameObject()
{
    _xCoord = Game::ORIGIN_X;
	_yCoord = Game::ORIGIN_Y;
    _angle = angle;
    _objectWidth = 20;
    _objectHeight = 20;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _health = 1;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / Game::PLAYER_RADIUS;
    _scaleCount = 0;
    _objectType = gameObjectType::Asteriod;
    _shapeProperties = {3.0, 255, 0, 0};

    
    float vecX = cos(_angle*(M_PI/180));
    float vecY = sin(_angle*(M_PI/180)); 
    
    _pathVector[0] = vecX*_SPEED_MULTIPLIER;
    _pathVector[1] = vecY*_SPEED_MULTIPLIER;
}