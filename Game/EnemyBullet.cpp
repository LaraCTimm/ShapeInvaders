#include "EnemyBullet.h"


EnemyBullet::EnemyBullet(float xCoord, float yCoord, sf::Vector2f enemyPathVector, float angle, int scaleCount) : GameObject()
{
    _xCoord = xCoord;
	_yCoord = yCoord;
    _angle = angle;
    _objectWidth = 20;
    _objectHeight = 20;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _health = 1;
    _points = 0;
    _scaleCount = scaleCount;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / Game::PLAYER_RADIUS;
    _scale += _scaleFactor*_scaleCount;
    _objectType = gameObjectType::EnemyBullet;
    
    const float SPEED_MULTIPLIER = 2.0f;
    
    float vecX = cos(_angle*(M_PI/180));//*Game::PLAYER_RADIUS;
    float vecY = sin(_angle*(M_PI/180));//*Game::PLAYER_RADIUS;

    _pathVector = sf::Vector2f(vecX*SPEED_MULTIPLIER, vecY*SPEED_MULTIPLIER); // start position of linear path
    _xCoord += _pathVector.x;
    _yCoord += _pathVector.y;
    //_pathVector = sf::Vector2f(enemyPathVector.x*SPEED_MULTIPLIER, enemyPathVector.y*SPEED_MULTIPLIER);

    // Create bullet rectangle
    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
    
    // Set bullet attributes
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));
    rectangle.setRotation(_angle);
    
    
    
//    _xCoord += enemyPathVector.x;
//	_yCoord += enemyPathVector.y; 

//    cout << enemyPathVector.x << " " << enemyPathVector.y << endl;
    
	rectangle.setPosition(_xCoord, _yCoord);
    
    setObjectShape(rectangle);
    
}

//EnemyBullet::void decrementEnemyBulletCooldown() 
//{
//    if (_cooldown > 0)
//        _cooldown--;
//}