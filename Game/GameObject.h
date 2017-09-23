#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;

#include <memory> // required for smart pointers
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

enum class gameObjectType 
{
	Player = 1, 
	Enemy,
    PlayerBullet,
    EnemyBullet,
    Asteriod,
    Satellite,
    LaserGenerator,
    ArcSegment
};

class GameObject
{

    static constexpr float BULLET_SPEED_MODIFIER = 20.0f;
    
public:

    // Constructor
    GameObject();

    // Move object by an offset
    void move(float xOffset, float yOffset);

    // Move object by calculating new co-ords and setting position
    void circularMove(int direction);
    void lineMove();

    void checkCollisions(vector<GameObject> &objectVector);

    void decrementBulletCooldown();
    

    virtual ~GameObject() {};
    

    // Accessors and Mutators ----------------------------

    float getXCoord() {
        return _xCoord;
    }

    void setXCoord(const float newXCoord) {
        _xCoord = newXCoord;
    }

    float getYCoord() {
        return _yCoord;
    }

    void setYCoord(const float newYCoord) {
        _yCoord = newYCoord;
    }
    ////
    float getObjectHeight() {
        return _objectHeight;
    }

    void setObjectHeight(const float newHeight) {
        _objectHeight = newHeight;
    }

    float getObjectWidth() {
        return _objectWidth;
    }

    void setObjectWidth(const float newWidth) {
        _objectWidth = newWidth;
    }

    float getAngle() {
        return _angle;
    }

    void setAngle(const float newAngle) {
        _angle = newAngle;
    }

    float getHitRadius() {
        return _hitRadius;
    }

    void setHitRadius(const float newHitRadius) {
        _hitRadius = newHitRadius;
    }

    /////
    float getBulletCooldown() {
        return _bulletCooldown;
    }
        
    void setBulletCooldown(float newBulletCooldown) {
        _bulletCooldown = newBulletCooldown;
    }
    /////

    int getHealth() {
        return _health;
    }

    void setHealth(const int newHealth) {
        _health = newHealth;
    }

    int getPoints() {
        return _points;
    }

    void setPoints(const int newPoints) {
        _points = newPoints;
    }

    int getScaleCount() {
        return _scaleCount;
    }

    void setScaleCount(const int newScaleCount) {
        _scaleCount = newScaleCount;
    }


    sf::RectangleShape getObjectShape() {
        return _objectShape;
    }

    //shared_ptr<sf::RectangleShape> getObjectShape() {
    //	auto objectShape_ptr = make_shared<sf::RectangleShape>(_objectShape);
    //    return objectShape_ptr;
    //}

    void setObjectShape(sf::RectangleShape newObjectShape) {
        _objectShape = newObjectShape;
    }

    sf::Vector2f getPathVector() {
        return _pathVector;
    }

    void setPathVector(sf::Vector2f newPathVector) {
        _pathVector = newPathVector;
    }

    gameObjectType getObjectType() {
        return _objectType;
    }



// variables are protected rather that private so that can be accessed by classes inherited by the GameObject class
protected:
    float _xCoord;
    float _yCoord;
    float _objectHeight;
    float _objectWidth;
	float _angle;
    float _hitRadius;
    float _bulletCooldown;
    int _health;
    int _points;
    float _scale;
    float _scaleFactor;
    int _scaleCount;
	sf::RectangleShape _objectShape;
    sf::Vector2f _pathVector;
    gameObjectType _objectType;

    
};

#endif