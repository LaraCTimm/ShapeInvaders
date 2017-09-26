#include "Asteriod.h"

Asteriod::Asteriod(float angle) : GameObject()
{
    _xCoord = Game::ORIGIN_X;
	_yCoord = Game::ORIGIN_Y;
    _angle = angle;
    _objectWidth = 35;
    _objectHeight = 35;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _health = 1;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / Game::PLAYER_RADIUS;
    _scaleCount = 0;
    _objectType = gameObjectType::Asteriod;
    
    float vecX = cos(_angle*(M_PI/180));//*Game::PLAYER_RADIUS;
    float vecY = sin(_angle*(M_PI/180));//*Game::PLAYER_RADIUS;
    
    _pathVector = sf::Vector2f(-(vecX*_SPEED_MULTIPLIER), -(vecY*_SPEED_MULTIPLIER);
    
    // Create bullet rectangle
    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
    
    // Set bullet attributes
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));
    rectangle.setRotation(_angle);
    rectangle.setPosition(_xCoord, _yCoord);
    setObjectShape(rectangle);

    //cout << _pathVector.x << " " << _pathVector.y << endl;
}

//void Asteriod::decrementAsteriodCooldown() 
//{
//    if (_cooldown > 0)
//        _cooldown--;
//}