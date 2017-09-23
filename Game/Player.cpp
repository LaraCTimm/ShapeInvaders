#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"

#include <iostream>
using std::cout;
using std::endl;

Player::Player() : GameObject()
{
    _angle = 0;
    _hitRadius = 25; 
    _objectWidth = 50;
    _objectHeight = 50;
    _health = 1;
    _points = 0;
    _scale = 1;
    _pathVector = sf::Vector2f(-15,0);
    _objectType = gameObjectType::Player;
    
    // Create player rectangle
    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
    
    // Set player attributes
    rectangle.setOutlineThickness(3);
    rectangle.setOutlineColor(sf::Color::Blue);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));

    // Set player start position
    _xCoord = Game::ORIGIN_X + cos(0)*Game::PATH_RADIUS;
	_yCoord = Game::ORIGIN_Y + sin(0)*Game::PATH_RADIUS;
    //cout << _xCoord << " " << _yCoord << endl;
	rectangle.setPosition(_xCoord, _yCoord);
    
    setObjectShape(rectangle);
    
}