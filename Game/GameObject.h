#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class Game; // not entirely sure why doing this fixed things, but hey
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>
#include <memory>

using std::sin;
using std::cos;
using std::pow;
using std::sqrt;
using std::cout;
using std::endl;
using std::vector;
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

class GameObject : public std::enable_shared_from_this<GameObject>
{
    
public:

    static constexpr float BULLET_SPEED_MODIFIER = 20.0f;
    // Constructor
    GameObject();
    
    virtual void circularMove(int direction);
    
    void lineMove();
    
    void checkInBounds();

    int checkCollisions(vector<shared_ptr<GameObject>> &objectVector);
    
    

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
    
    float getScale() {
        return _scale;
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

    vector<float> getPathVector() {
        return _pathVector;
    }

    void setPathVector(vector<float> newPathVector) {
        _pathVector = newPathVector;
    }
    
    vector<float> getShapeProperties() {
        return _shapeProperties;
    }
    
    void setShapeProperties(vector<float> shapeProperties) {
        _shapeProperties = shapeProperties;
    }

    gameObjectType getObjectType() {
        return _objectType;
    }
    
    std::shared_ptr<GameObject> getptr() {
        return shared_from_this();
    }



// variables are protected rather that private so that can be accessed by classes inherited by the GameObject class
protected:
    float _xCoord;
    float _yCoord;
    float _objectHeight;
    float _objectWidth;
	float _angle;
    float _hitRadius;
    int _health;
    int _points;        
    float _scale;
    float _scaleFactor;
    int _scaleCount;    
    vector<float> _pathVector;
    vector<float> _shapeProperties;
    gameObjectType _objectType;
    
private:

    
};


#endif