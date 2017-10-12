#include "PlayerBullet.h"

#include <iostream>
using std::cout;
using std::endl;

PlayerBullet::PlayerBullet(float xCoord, float yCoord, vector<float> pathVector, float angle) : GameObject()
{
    _angle = angle;
    _objectWidth = 9;
    _objectHeight = 9;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _health = 1;
    _points = 0;
    _scale = 1;
    _scaleFactor = -0.035;
    _scaleCount = 0;
    _objectType = gameObjectType::PlayerBullet;
    _pathVector = pathVector;
    _xCoord = xCoord + pathVector[0];
	_yCoord = yCoord + pathVector[1];
    
}