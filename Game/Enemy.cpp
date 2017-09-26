#include "Enemy.h"

Enemy::Enemy(float xCoord, float yCoord, float angle) : GameObject()
{
    _xCoord = xCoord;
	_yCoord = yCoord;
    _angle = angle;
    _objectWidth = 50;
    _objectHeight = 50;
    _hitRadius = (_objectWidth + _objectHeight)/4;
    _bulletCooldown = 25;

    _health = 1;
    _points = 0;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / Game::PLAYER_RADIUS;
    _scaleCount = 0;
    _objectType = gameObjectType::Enemy;
    
    float vecX = cos(_angle*(M_PI/180));
    float vecY = sin(_angle*(M_PI/180));
    
    vecX = -vecX;
    vecY = -vecY;
    _pathVector = sf::Vector2f(vecX, vecY); // start position of linear path
    cout << vecX << " " << vecY << " " << angle << " Enemy" << endl;
    

    // Create bullet rectangle
    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
    
    // Set bullet attributes
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));
    rectangle.setRotation(_angle);
    rectangle.setPosition(_xCoord, _yCoord);
    setObjectShape(rectangle);

}

//void Enemy::decrementEnemyCooldown() 
//{
//    if (_cooldown > 0)
//        _cooldown--;
//}

void Enemy::decrementEnemyBulletCooldown() 
{
    if (_bulletCooldown > 0)
        _bulletCooldown--;
}