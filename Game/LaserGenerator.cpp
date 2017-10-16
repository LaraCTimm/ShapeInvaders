#include "LaserGenerator.h"

LaserGenerator::LaserGenerator (float degrees, int ID) : GameObject()
{
    _xCoord = Game::ORIGIN_X;
	_yCoord = Game::ORIGIN_Y;
    _angle = degrees;
    _objectWidth = 35;
    _objectHeight = 25;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _health = 1;
    _points = 20;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / Game::PLAYER_RADIUS;
    _scaleCount = 0;
    _objectType = gameObjectType::LaserGenerator;
    _shapeProperties = {3.0, 255, 52, 0};

    
    float vecX = cos(_angle*(M_PI/180));
    float vecY = sin(_angle*(M_PI/180));
    
    const float SPEED_MULTIPLIER = 1.0f;
    
    vecX = vecX * SPEED_MULTIPLIER;
    vecY = vecY * SPEED_MULTIPLIER;
    _xCoord += 2*vecX;
	_yCoord += 2*vecY;
    _pathVector[0] = vecX;
    _pathVector[1] = vecY;
    _ID = ID;
    
}

