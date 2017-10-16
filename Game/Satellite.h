#ifndef SATELLITE_H
#define SATELLITE_H
        
#include "GameObject.h"
#include "Game.h"

/**
 * @class Satellite
 * @brief Represents a satellite object. 
 * 
 * Inherited from the GameObject Class.
 */

class Satellite : public GameObject
{
public:

    static constexpr float SATELLITE_DEVIATION = 20.0f;
    
    /**
     * @brief Satellite Constructor.
     * @param offsetAngle - float angle representing the offset from the player angle.
     * @param ID - integer ID which belongs to a three independant satellites which 
     * spawn together in front of the player.
     */
    Satellite(float offsetAngle, int ID);
    
    /**
     * @brief Function which controls the circular movement of the satellites.
     * Satellites gyrate in small circles around their own pivotal point in one 
     * of two possible directions.
     * @param direction - integer direction which is either positive or negative 1.
     */
    void circularMove(int direction) override;
    
    
    /**
     * @brief Returns the gyration angle of the satellite.
     * This parameter is used to trigger satellites firing bullets at the player.
     * @return Gyration angle of the satellite.
     */
    float getGyrateAngle() {
        return _gyrateAngle;
    }
    /**
     * @brief Returns a bool which flags when a new bullet can be fired.
     * @return Bool which is true when a new shot can be fired.
     */
    bool getShotCharged() {
        return _shotCharged;
    }
    /**
     * @brief Allowes the bool for satellite bullets to be set.
     * @param charged - bool which sets the shorCharged variable.
     */
    void setShotCharged(bool charged) {
        _shotCharged = charged;
    }
    /**
     * @brief Gets satellites's ID, unique to an array of three satellites.
     * @return Satellite's ID.
     */
    int getID() {
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