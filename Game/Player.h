#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Game.h"

/**
 * @class Player
 * @brief Represents the player object.
 * 
 * Inherited from the GameObject Class.
 */

class Player : public GameObject
{
public:

    static constexpr int BULLET_OFFSET_ANGLE = 4.5;
    
    /**
     * @brief Player constructor.
     */
    Player();
   
    /**
     * @brief Function which controls circular movenent of the player.
     * 
     * Player moves on the circumference of a large circle in one of two directions.
     * @param direction - integer direction which is either positive or negative 1.
     */
    void circularMove(int direction) override;
    
    /**
     * @brief Allows the players gun to be upgraded.
     * 
     * Upon destroying three satillites the player gets a gun upgrade. An extra bullet 
     * is added which makes firing much more effective.
     */
    void UpgradeGun();


    /**
     * @brief Function returning the gun level of the player.
     * @return Integer gun level.
     */
    int getGunLevel() {
        return _gunLevel;
    }
    /**
     * @brief Function returning the path vector for the left hand bullet.
     * @return Path vector for the left bullet.
     */
    vector<float> getPathVectorLeft() {
        return _pathVectorLeft;
    }
    /**
     * @brief Function returning the path vector for the right hand bullet.
     * @return Path vector for the right bullet.
     */
    vector<float> getPathVectorRight() {
        return _pathVectorRight;
    }
    /**
     * @brief Function returning the starting x-coordinate for the left bullet.
     * @return Starting x-coordinate for the left bullet.
     */
    float getXCoordLeft() {
        return _xCoordLeft;
    }
    /**
     * @brief Function returning the starting y-coordinate for the left bullet.
     * @return Starting y-coordinate for the left bullet.
     */
    float getYCoordLeft() {
        return _yCoordLeft;
    }
    
    /**
     * @brief Function returning the starting x-coordinate for the right bullet.
     * @return Starting x-coordinate for the right bullet.
     */
    float getXCoordRight() {
        return _xCoordRight;
    }
    
    /**
     * @brief Function returning the starting y-coordinate for the right bullet.
     * @return Starting y-coordinate for the right bullet.
     */
    float getYCoordRight() {
        return _yCoordRight;
    }
    
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
    
    /**
     * @brief Sets up path vectors for multiple bullets.
     * 
     * When the players gun is upgraded, alternate path vectors are required for
     * the additional bullets to travel along. 
     */
    void SetMultiBulletVectors();
    
    
};

#endif