#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Game.h"
#include "math.h"
using std::sin;
using std::cos;
using std::pow;
using std::sqrt;
#include <iostream>
using std::cout;
using std::endl;

GameObject::GameObject()
{   }

void GameObject::move(float xOffset, float yOffset)
{
	_objectShape.move(xOffset, yOffset);
}


void GameObject::circularMove(int direction)
{
	_angle += direction; // positive or negative
    float vecX = cos(_angle*M_PI/90)*Game::PATH_RADIUS;
    float vecY = sin(_angle*M_PI/90)*Game::PATH_RADIUS;
	_xCoord = Game::ORIGIN_X + vecX;
	_yCoord = Game::ORIGIN_Y + vecY;
	_objectShape.setPosition(_xCoord, _yCoord);
    _objectShape.setRotation(_angle*2);
	//cout << _xCoord << " " << _yCoord << " " << _angle <<  endl;
    
    vecX = -vecX/PLAYER_BULLET_SPEED_MODIFIER;
    vecY = -vecY/PLAYER_BULLET_SPEED_MODIFIER;
    _pathVector = sf::Vector2f(vecX, vecY);

}

void GameObject::lineMove()
{
	_xCoord += _pathVector.x;
	_yCoord += _pathVector.y;
	_objectShape.setPosition(_xCoord, _yCoord);
    
    _scale += _scaleFactor;
    _scaleCount++;
    
    if (_scale > 1) {
        _scale = 1;
    }
    
    sf::Vector2f newSize(_objectWidth*_scale, _objectHeight*_scale);
    _objectShape.setSize(newSize);
    _objectShape.setOrigin(_objectShape.getSize().x/2, _objectShape.getSize().y/2);
    _hitRadius = (_objectShape.getSize().y + _objectShape.getSize().x)/4;
    //_objectHeight*_scale/4;
    //cout<< _hitRadius << endl;
     
    
    
    // Check bullet reaches screen centre
    if (_objectType == gameObjectType::PlayerBullet && (_xCoord >= 395 && _xCoord <= 405 && _yCoord >= 395 && _yCoord <= 405))
    {
        _health = 0;
    }
    
    // Check enemy goes off the screen
    if ((_objectType == gameObjectType::Enemy || _objectType == gameObjectType::EnemyBullet || _objectType == gameObjectType::Asteriod) && (_xCoord >= 850 || _xCoord <= -50 || _yCoord >= 850 || _yCoord <= -50))
    {
        _health = 0;
    }
    
}

void GameObject::checkCollisions(vector<GameObject> objectVector)
{
    for (auto element : objectVector)
    {
        if (element.getObjectType() == gameObjectType::PlayerBullet && _objectType == gameObjectType::Enemy)
        {
            float distance = sqrt(pow(element.getXCoord()-_xCoord,2) + pow(element.getYCoord()-_yCoord,2));
            if (distance <= element.getHitRadius()+_hitRadius)
            {
                _health = 0;                
            }
        }
        
        if (element.getObjectType() == gameObjectType::Enemy && _objectType == gameObjectType::PlayerBullet)
        {
            float distance = sqrt(pow(element.getXCoord()-_xCoord,2) + pow(element.getYCoord()-_yCoord,2));
            if (distance <= element.getHitRadius()+_hitRadius)
                _health = 0;
        }
        
        if (element.getObjectType() == gameObjectType::Enemy && _objectType == gameObjectType::Player)
        {
            float distance = sqrt(pow(element.getXCoord()-_xCoord,2) + pow(element.getYCoord()-_yCoord,2));
            if (distance <= element.getHitRadius()+_hitRadius)
                _health = 0;
        }
        
        if (element.getObjectType() == gameObjectType::Player && _objectType == gameObjectType::Enemy)
        {
            float distance = sqrt(pow(element.getXCoord()-_xCoord,2) + pow(element.getYCoord()-_yCoord,2));
            if (distance <= element.getHitRadius()+_hitRadius)
            {
                //cout << "ENEMY " << _xCoord << " " << _yCoord << endl;
                //cout << "ENEMY " << _objectShape.getPosition().x << " " << _objectShape.getPosition().y << endl;
                _health = 0;
                
            }
        }
        
        if (element.getObjectType() == gameObjectType::EnemyBullet && _objectType == gameObjectType::Player)
        {
            float distance = sqrt(pow(element.getXCoord()-_xCoord,2) + pow(element.getYCoord()-_yCoord,2));
            if (distance <= element.getHitRadius()+_hitRadius)
                _health = 0;
        }
        
        if (element.getObjectType() == gameObjectType::Player && _objectType == gameObjectType::EnemyBullet)
        {
            float distance = sqrt(pow(element.getXCoord()-_xCoord,2) + pow(element.getYCoord()-_yCoord,2));
            if (distance <= element.getHitRadius()+_hitRadius)
                _health = 0;
        }
        
        if (element.getObjectType() == gameObjectType::Asteriod && _objectType == gameObjectType::Player)
        {
            float distance = sqrt(pow(element.getXCoord()-_xCoord,2) + pow(element.getYCoord()-_yCoord,2));
            if (distance <= element.getHitRadius()+_hitRadius)
            {
                //cout << "ENEMY " << _xCoord << " " << _yCoord << endl;
                //cout << "ENEMY " << _objectShape.getPosition().x << " " << _objectShape.getPosition().y << endl;
                _health = 0;
                
            }
        }
    }
}

void GameObject::decrementBulletCooldown()
{
    if (_bulletCooldown > 0)
        _bulletCooldown--;
}