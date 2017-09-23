#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Game.h"
#include "math.h"
using std::sin;
using std::cos;
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
	cout << _xCoord << " " << _yCoord << " " << _angle <<  endl;
    
    vecX = -vecX/20;
    vecY = -vecY/20;
    _pathVector = sf::Vector2f(vecX, vecY); // start position of linear path

}

void GameObject::lineMove()
{
	_xCoord += _pathVector.x;
	_yCoord += _pathVector.y;
	_objectShape.setPosition(_xCoord, _yCoord);
    
    _scale += _scaleFactor;
    sf::Vector2f newScale(_scale, _scale);
    _objectShape.setScale(newScale);
    
    
    // Check bullet reaches screen centre
    if (_objectType == gameObjectType::PlayerBullet && _xCoord >= 395 && _xCoord <= 405 && _yCoord >= 395 && _yCoord <= 405)
    {
        _health = 0;
    }
    //cout << _xCoord << " " << _yCoord << endl;
    //cout << _pathVector.x << " " << _pathVector.y << endl;
}
