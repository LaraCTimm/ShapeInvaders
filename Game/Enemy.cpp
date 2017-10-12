#include "Enemy.h"

Enemy::Enemy(float xCoord, float yCoord, float angle) : GameObject()
{
    _xCoord = xCoord;
	_yCoord = yCoord;
    _angle = angle;
    _objectWidth = 50;
    _objectHeight = 50;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _bulletCooldown = 25;

    _health = 1;
    _points = 10;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / Game::PLAYER_RADIUS;
    _scaleCount = 0;
    _objectType = gameObjectType::Enemy;
    _shapeProperties = {3.0, 0, 255, 65};

    
    float vecX = cos(_angle*(M_PI/180));
    float vecY = sin(_angle*(M_PI/180));
    
    _pathVector[0] = vecX;
    _pathVector[1] = vecY;
    
    _xCoord += 2*vecX;
    _yCoord += 2*vecY;
}


void Enemy::decrementEnemyBulletCooldown() 
{
    if (_bulletCooldown > 0)
        _bulletCooldown--;
}