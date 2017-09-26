#include "ArcSegment.h"

ArcSegment::ArcSegment(float angle, int ID) : GameObject()
{
    _xCoord = Game::ORIGIN_X;
	_yCoord = Game::ORIGIN_Y;
    _angle = angle;
    _objectWidth = 15;
    _objectHeight = 40;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _health = 1;
    _points = 10;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / 275;//Game::PATH_RADIUS;
    _scaleCount = 0;
    _objectType = gameObjectType::ArcSegment;
    
    float vecX = cos(_angle*(M_PI/180));
    float vecY = sin(_angle*(M_PI/180));
    
    const float SPEED_MULTIPLIER = 1.0f;
    
    vecX = vecX * SPEED_MULTIPLIER;
    vecY = vecY * SPEED_MULTIPLIER;
    _xCoord += 2*vecX;
	_yCoord += 2*vecY;
    _pathVector = sf::Vector2f(vecX, vecY);
    
    // Create rectangle
    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
    
    // Set attributes
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));
    rectangle.setRotation(angle);
    rectangle.setPosition(_xCoord, _yCoord);
    setObjectShape(rectangle);
    
    _ID = ID;
}