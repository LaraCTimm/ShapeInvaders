#include "Satellite.h"

Satellite::Satellite(float offsetAngle, int ID) : GameObject()
{
    _angle = offsetAngle;
    _objectWidth = 15;
    _objectHeight = 15;
    _hitRadius = (_objectWidth+4 + _objectHeight+4)/4; 
    _health = 5;
    _points = 30;
    _scale = 1;
    _scaleCount = 10;
    _ID = ID;
    _shotCharged = false;
    
    _pathVector[0] = _BULLET_OFFSET_X;
    _pathVector[1] = _BULLET_OFFSET_Y;
    _objectType = gameObjectType::Satellite;
    
    _gyrateCoordX = Game::ORIGIN_X + cos(_angle * M_PI / 180)*Game::PLAYER_RADIUS*3/5;
    _gyrateCoordY = Game::ORIGIN_Y + sin(_angle * M_PI / 180)*Game::PLAYER_RADIUS*3/5;
    
    float gyrateRadius = 30;
    _gyrateAngle = offsetAngle;
    
    _xCoord = _gyrateCoordX + cos(_gyrateAngle * M_PI / 180)*gyrateRadius;
	_yCoord = _gyrateCoordY + sin(_gyrateAngle * M_PI / 180)*gyrateRadius;
    
    _shapeProperties = {2.0f};
}

void Satellite::circularMove(int direction)
{
    float gyrateRadius = 30;
	_gyrateAngle += 2*direction; 
    
    
    if(_gyrateAngle > 360) {
        _gyrateAngle -= 360;
    }
    else if(_gyrateAngle < 0) {
        _gyrateAngle += 360;
    }
    
    if(_gyrateAngle >= _angle - 5 && _gyrateAngle <= _angle + 5) {
        _shotCharged = true;
    }
    
    float vecX = cos(_gyrateAngle*(M_PI/180))*gyrateRadius;
    float vecY = sin(_gyrateAngle*(M_PI/180))*gyrateRadius;
	_xCoord = _gyrateCoordX + vecX;
	_yCoord = _gyrateCoordY + vecY;
    
    vecX = vecX/BULLET_SPEED_MODIFIER;
    vecY = vecY/BULLET_SPEED_MODIFIER;
    
    _pathVector[0] = vecX;
    _pathVector[1] = vecY;
}