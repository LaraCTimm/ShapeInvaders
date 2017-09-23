#include "Enemy.h"

#include <iostream>
using std::cout;
using std::endl;

Enemy::Enemy(float xCoord, float yCoord, sf::Vector2f pathVector, float angle) : GameObject()
{
    _hitRadius = 5;
    _objectWidth = 50;
    _objectHeight = 50;
    _health = 1;
    _points = 0;
    _scale = 0.2;
    _scaleFactor = 0.08;
    _objectType = gameObjectType::Enemy;
    _pathVector = -pathVector;

    // Create bullet rectangle
    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
    
    // Set bullet attributes
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));
    rectangle.setRotation(angle*2);

    
    _xCoord = xCoord + pathVector.x;
	_yCoord = yCoord + pathVector.y;
    cout << pathVector.x << " " << pathVector.y << endl;
    
	rectangle.setPosition(_xCoord, _yCoord);
    
    setObjectShape(rectangle);
    
}