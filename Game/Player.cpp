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
    _gunLevel = 3;
    
    _pathVectorLeft = {0.0f,0.0f};
    _pathVectorRight = {0.0f,0.0f};
    
    _pathVector[0] = _BULLET_OFFSET_X;
    _pathVector[1] = _BULLET_OFFSET_Y;
    
    _pathVectorLeft[0] = _BULLET_OFFSET_X;
    _pathVectorLeft[1] = _BULLET_OFFSET_Y - 20.0f;
    
    _pathVectorRight[0] = _BULLET_OFFSET_X;
    _pathVectorRight[1] = _BULLET_OFFSET_Y + 20.0f;
    
    _objectType = gameObjectType::Player;
    // Set player start position
    _xCoord = Game::ORIGIN_X + cos(0)*Game::PLAYER_RADIUS;
	_yCoord = Game::ORIGIN_Y + sin(0)*Game::PLAYER_RADIUS;
    
    SetMultiBulletVectors();
    
    
    
    
    
    
    
    
    //_pathVector = sf::Vector2f(_BULLET_OFFSET_X, _BULLET_OFFSET_Y);
    // Create player rectangle
//    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
//    
//    // Set player attributes
//    rectangle.setOutlineThickness(3);
//    rectangle.setOutlineColor(sf::Color::Blue);
//    rectangle.setFillColor(sf::Color::White);
//    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));
//
//	rectangle.setPosition(_xCoord, _yCoord);
//    
//    setObjectShape(rectangle);
    
}

void Player::circularMove(int direction)
{
    // control circular movement
	_angle += 2*direction; // positive or negative
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
        float vecXLeft = cos((_angle - BULLET_OFFSET_ANGLE)*(M_PI/180))*Game::PLAYER_RADIUS;
    float vecYLeft = sin((_angle - BULLET_OFFSET_ANGLE)*(M_PI/180))*Game::PLAYER_RADIUS;
	_xCoordLeft = Game::ORIGIN_X + vecXLeft;
	_yCoordLeft = Game::ORIGIN_Y + vecYLeft;
    
    vecXLeft = -vecXLeft/GameObject::BULLET_SPEED_MODIFIER;
    vecYLeft = -vecYLeft/GameObject::BULLET_SPEED_MODIFIER;
    
    _pathVectorLeft[0] = vecXLeft;
    _pathVectorLeft[1] = vecYLeft;
    
    
    float vecXRight = cos((_angle + BULLET_OFFSET_ANGLE)*(M_PI/180))*Game::PLAYER_RADIUS;
    float vecYRight = sin((_angle + BULLET_OFFSET_ANGLE)*(M_PI/180))*Game::PLAYER_RADIUS;
	_xCoordRight = Game::ORIGIN_X + vecXRight;
	_yCoordRight = Game::ORIGIN_Y + vecYRight;
    
    vecXRight = -vecXRight/GameObject::BULLET_SPEED_MODIFIER;
    vecYRight = -vecYRight/GameObject::BULLET_SPEED_MODIFIER;
    
    _pathVectorRight[0] = vecXRight;
    _pathVectorRight[1] = vecYRight;
}