#ifndef SATELLITE_H
#define SATELLITE_H
        
#include "GameObject.h"
#include "Game.h"

class Satellite : public GameObject
{
public:

    static constexpr float SATELLITE_DEVIATION = 20.0f;

    float getGyrateAngle() {
        return _gyrateAngle;
    }
    
    bool getShotCharged()
    {
        return _shotCharged;
    }
    
    void setShotCharged(bool charged)
    {
        _shotCharged = charged;
    }

    Satellite(float offsetAngle, int ID);
    
    void circularMove(int direction) override;
    
    int &getID() {
    return _ID;
}

    
private:

    const float _BULLET_OFFSET_X = -15;
    const float _BULLET_OFFSET_Y = 0;
    int _ID;

    float _gyrateAngle;
    float _gyrateCoordX;
    float _gyrateCoordY;
    bool _shotCharged;
};

#endif