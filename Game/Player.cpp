#include "Player.h"

Player::Player() : GameObject()
{
    _angle = 0;
    _objectWidth = 50;
    _objectHeight = 50;
    _hitRadius = (_objectWidth + _objectHeight)/4; 
    _health = 5;
    _points = 0;
    _scale = 1;
    _gunLevel = 1;
    
    _pathVectorLeft = {0.0f,0.0f};
    _pathVectorRight = {0.0f,0.0f};
    
    _pathVector[0] = _BULLET_OFFSET_X;
    _pathVector[1] = _BULLET_OFFSET_Y;
    
    _pathVectorLeft[0] = _BULLET_OFFSET_X;
    _pathVectorLeft[1] = _BULLET_OFFSET_Y - 20.0f;
    
    _pathVectorRight[0] = _BULLET_OFFSET_X;
    _pathVectorRight[1] = _BULLET_OFFSET_Y + 20.0f;
    
    _objectType = gameObjectType::Player;
    
    _xCoord = Game::ORIGIN_X + cos(0)*Game::PLAYER_RADIUS;
	_yCoord = Game::ORIGIN_Y + sin(0)*Game::PLAYER_RADIUS;
    
    SetMultiBulletVectors();
}

void Player::circularMove(int direction)
{
	_angle += 2*direction;
    
    if(_angle > 360)
    {
        _angle -= 360;
    }
    else if(_angle < 0)
    {
        _angle += 360;
    }
    
    float vecX = cos(_angle*(M_PI/180))*Game::PLAYER_RADIUS;
    float vecY = sin(_angle*(M_PI/180))*Game::PLAYER_RADIUS;
	_xCoord = Game::ORIGIN_X + vecX;
	_yCoord = Game::ORIGIN_Y + vecY;

    vecX = -vecX/GameObject::BULLET_SPEED_MODIFIER;
    vecY = -vecY/GameObject::BULLET_SPEED_MODIFIER;
    
    _pathVector[0] = vecX;
    _pathVector[1] = vecY;
    
    SetMultiBulletVectors();
}

void Player::SetMultiBulletVectors()
{
    //// LEFT ////
    float vecXLeft = cos((_angle - BULLET_OFFSET_ANGLE)*(M_PI/180))*Game::PLAYER_RADIUS;
    float vecYLeft = sin((_angle - BULLET_OFFSET_ANGLE)*(M_PI/180))*Game::PLAYER_RADIUS;
	_xCoordLeft = Game::ORIGIN_X + vecXLeft;
	_yCoordLeft = Game::ORIGIN_Y + vecYLeft;
    
    vecXLeft = -vecXLeft/GameObject::BULLET_SPEED_MODIFIER;
    vecYLeft = -vecYLeft/GameObject::BULLET_SPEED_MODIFIER;
    
    _pathVectorLeft[0] = vecXLeft;
    _pathVectorLeft[1] = vecYLeft;
    

    //// RIGHT ////
    float vecXRight = cos((_angle + BULLET_OFFSET_ANGLE)*(M_PI/180))*Game::PLAYER_RADIUS;
    float vecYRight = sin((_angle + BULLET_OFFSET_ANGLE)*(M_PI/180))*Game::PLAYER_RADIUS;
	_xCoordRight = Game::ORIGIN_X + vecXRight;
	_yCoordRight = Game::ORIGIN_Y + vecYRight;
    
    vecXRight = -vecXRight/GameObject::BULLET_SPEED_MODIFIER;
    vecYRight = -vecYRight/GameObject::BULLET_SPEED_MODIFIER;
    
    _pathVectorRight[0] = vecXRight;
    _pathVectorRight[1] = vecYRight;
}

void Player::UpgradeGun()
{
    if(_gunLevel < 3)
    {
        _gunLevel++;
    }
}