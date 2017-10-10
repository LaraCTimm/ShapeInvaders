#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Game.h"

class Player : public GameObject
{
public:

    Player();
    
    static constexpr int BULLET_OFFSET_ANGLE = 5;
    
    int getGunLevel() {
        return _gunLevel;
    }
    
    void setGunLevel(int gunLevel) {
        _gunLevel = gunLevel;
    }
    
    vector<float> getPathVectorLeft() {
        return _pathVectorLeft;
    }
    
    void setPathVectorLeft(vector<float> newPathVector) {
        _pathVectorLeft = newPathVector;
    }
    
    vector<float> getPathVectorRight() {
        return _pathVectorRight;
    }
    
    void setPathVectorRight(vector<float> newPathVector) {
        _pathVectorLeft = newPathVector;
    }
    
    float getXCoordLeft() {
        return _xCoordLeft;
    }

    void setXCoordLeft(const float newXCoord) {
        _xCoordLeft = newXCoord;
    }

    float getYCoordLeft() {
        return _yCoordLeft;
    }

    void setYCoordLeft(const float newYCoord) {
        _yCoordLeft = newYCoord;
    }
    
    float getXCoordRight() {
        return _xCoordRight;
    }

    void setXCoordRight(const float newXCoord) {
        _xCoordRight = newXCoord;
    }

    float getYCoordRight() {
        return _yCoordRight;
    }

    void setYCoordRight(const float newYCoord) {
        _yCoordRight = newYCoord;
    }
    
    void circularMove(int direction) override;
    
    
    
private:

    const float _BULLET_OFFSET_X = -15;
    const float _BULLET_OFFSET_Y = 0;
    
    vector<float> _pathVectorLeft;
    vector<float> _pathVectorRight;
    float _xCoordLeft;
    float _yCoordLeft;
    float _xCoordRight;
    float _yCoordRight;
    
    int _gunLevel;
    
    void SetMultiBulletVectors();
    
    
};

#endif