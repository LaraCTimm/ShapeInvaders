#include "PlayerBullet.h"

#include <iostream>
using std::cout;
using std::endl;

PlayerBullet::PlayerBullet(float xCoord, float yCoord, sf::Vector2f pathVector, float angle) : GameObject()
{
    _angle = angle;
    _objectWidth = 10;
    _objectHeight = 10;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _health = 1;
    _points = 0;
    _scale = 1;
    _scaleFactor = -0.035; //// FIX THIS
    _scaleCount = 0;
    _objectType = gameObjectType::PlayerBullet;
    _pathVector = pathVector;

    // Create bullet rectangle
    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
    
    // Set bullet attributes
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));
    rectangle.setRotation(angle);

    
    _xCoord = xCoord + pathVector.x;
	_yCoord = yCoord + pathVector.y;
    cout << pathVector.x << " " << pathVector.y << endl;
    
	rectangle.setPosition(_xCoord, _yCoord);
    
    setObjectShape(rectangle);
    
}