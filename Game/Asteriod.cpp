#include "Asteriod.h"
#include "Game.h"

#include <iostream>
using std::cout;
using std::endl;

Asteriod::Asteriod(float xCoord, float yCoord, float angle) : GameObject()
{
    _xCoord = xCoord;
	_yCoord = yCoord;
    _angle = angle;
    _objectWidth = 35;
    _objectHeight = 35;
    _hitRadius = (_objectWidth + _objectHeight)/4;
//    _bulletCooldown = 25;
    _health = 1;
//    _points = 0;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / Game::PATH_RADIUS;
    _scaleCount = 0;
    _objectType = gameObjectType::Asteriod;
    
    float vecX = cos(_angle*M_PI/90);//*Game::PATH_RADIUS;
    float vecY = sin(_angle*M_PI/90);//*Game::PATH_RADIUS;
    
    const float SPEED_MULTIPLIER = 2.0f;
    
    vecX = -vecX * SPEED_MULTIPLIER;//300;
    vecY = -vecY * SPEED_MULTIPLIER;//300;
    _pathVector = sf::Vector2f(vecX, vecY);
    
    // Create bullet rectangle
    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
    
    // Set bullet attributes
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));
    rectangle.setRotation(_angle*2);
    rectangle.setPosition(_xCoord, _yCoord);
    setObjectShape(rectangle);

    //cout << _pathVector.x << " " << _pathVector.y << endl;
}