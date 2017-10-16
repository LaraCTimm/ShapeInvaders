#include "EnemyBullet.h"


EnemyBullet::EnemyBullet(float xCoord, float yCoord, vector<float> enemyPathVector, float angle, int scaleCount) : GameObject()
{
    _xCoord = xCoord;
	_yCoord = yCoord;
    _angle = angle;
    _objectWidth = 20;
    _objectHeight = 5;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _health = 1;
    _points = 0;
    _scaleCount = scaleCount;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / Game::PLAYER_RADIUS;
    _scale += _scaleFactor*_scaleCount;
    _objectType = gameObjectType::EnemyBullet;
    _shapeProperties = {3.0, 255, 255, 255};

    
    float vecX = cos(_angle*(M_PI/180));
    float vecY = sin(_angle*(M_PI/180));

    _pathVector[0] = vecX*SPEED_MULTIPLIER;
    _pathVector[1] = vecY*SPEED_MULTIPLIER;
    
    _xCoord += _pathVector[0];
    _yCoord += _pathVector[1];

}
