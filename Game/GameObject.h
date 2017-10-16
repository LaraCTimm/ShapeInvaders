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

/**
 * @class GameObject - Base class from which all game objects are derived.
 * The game object class handles the movement and deletion of all game objects.
 * The inheritance of this class alows shared pointes to GameObjects to be created.
 * This allows for static pointer casting for access of dervied class functions.
 */

class GameObject : public std::enable_shared_from_this<GameObject>
{
    
public:

    static constexpr float BULLET_SPEED_MODIFIER = 20.0f;

    
    /**
     * @brief GameObject constructor.
     */
    GameObject();

    /**
     * @brief Virtual function which enables circular movement of game objects. 
     * Circular movement involves game objects moving around the circumference of a circle
     * on one dierction or the other.
     * @param direction - integer direction which is either positive or negative 1.
     */
    virtual void circularMove(int direction);
    
    /**
     * @brief Function enabling game objects to move linearly.
     * Object movement is defined by a path vector. Objects move radially outwards 
     * from the circle's centre or radially inwards towards the circle's centre.
     */
    void lineMove();
    
    /**
     * @brief Flags all game objects which are out of counds for cleanup.
     * If game objects travel off the screen, or if they reach the centre of the
     * screen they are flagged to be deleted.
     */
    void checkInBounds();

    /**
     * @brief Performs collision detection, flags objects for deletion.
     * A collision is detected when the distance between two objects is smaller than 
     * the sum of their hit radii. The approriate amount of health is deducted from
     * game objects upon their collision with other game objects.
     * @param objectVector - vector containing shared pointers to all existing game objects.
     * @return Integer score accumulated by the player as a result of a player bullet 
     * collision with a destroyable object.
     */
    int checkCollisions(vector<shared_ptr<GameObject>> &objectVector);
    
    
    /**
     * @brief Returns a shared pointer to the GameObject in question.
     * @return A shared pointer to a GameObject object.
     */
    std::shared_ptr<GameObject> getptr() {
        return shared_from_this();
    }
    /**
     * @brief Returns the x-coordinate of the GameObjects's position.
     * @return Float x-coordinate value.
     */
    float getXCoord() {
        return _xCoord;
    }
//
//    void setXCoord(const float newXCoord) {
//        _xCoord = newXCoord;
//    }

    /**
     * @brief Returns the y-coordinate of the GameObjects's position.
     * @return Float y-coordinate value.
     */
    float getYCoord() {
        return _yCoord;
    }
//
//    void setYCoord(const float newYCoord) {
//        _yCoord = newYCoord;
//    }
    
    /**
     * @brief Returns the scale of the GameObject.
     * @return Float scale value.
     */
    float getScale() {
        return _scale;
    }
    
    /**
     * @brief Returns the height of the GameObject.
     * @return Float height value.
     */
    float getObjectHeight() {
        return _objectHeight;
    }

//    void setObjectHeight(const float newHeight) {
//        _objectHeight = newHeight;
//    }

    /**
     * @brief Returns the width of the GameObject.
     * @return Float width value.
     */
    float getObjectWidth() {
        return _objectWidth;
    }

//    void setObjectWidth(const float newWidth) {
//        _objectWidth = newWidth;
//    }

    /**
     * @brief Returns the angle of the GameObject.
     * @return Float angle value.
     */
    float getAngle() {
        return _angle;
    }
//
//    void setAngle(const float newAngle) {
//        _angle = newAngle;
//    }

    /**
     * @brief Returns the hit-radius of the GameObject.
     * @return Float hit-radius value.
     */
    float getHitRadius() {
        return _hitRadius;
    }

//    void setHitRadius(const float newHitRadius) {
//        _hitRadius = newHitRadius;
//    }
    
    /**
     * @brief Returns the remaining health of the GameObject.
     * @return Integer health value.
     */
    int getHealth() {
        return _health;
    }
    
    /**
     * @brief Allows the health of the GameObject to be set.
     * @param newHealth - new integer health value.
     */
    void setHealth(const int newHealth) {
        _health = newHealth;
    }

    /**
     * @brief Returns the points value of the GameObject.
     * @return Integer points value.
     */
    int getPoints() {
        return _points;
    }

//    void setPoints(const int newPoints) {
//        _points = newPoints;
//    }

    /**
     * @brief Returns the scale-count value of the GameObject.
     * The scale count parameter keeps track of the position of a GameObject which
     * moves linearly, enabling a bullet to be fired from that GameObject which
     * is correctly scaled.
     * @return Integer scale-count value.
     */
    int getScaleCount() {
        return _scaleCount;
    }

//    void setScaleCount(const int newScaleCount) {
//        _scaleCount = newScaleCount;
//    }
    
    /**
     * @brief Returns the vector path vector of the GameObject.
     * The path vector defines the path of linear movement of a GameObject.
     * @return Vector of two floats defining the GameObject's path vector.
     */
    vector<float> getPathVector() {
        return _pathVector;
    }

//    void setPathVector(vector<float> newPathVector) {
//        _pathVector = newPathVector;
//    }

    /**
     * @brief Returns an enumeration indicating the GameObject's type.
     * @return Enumeration indicating the type of the GameObject.
     */
    gameObjectType getObjectType() {
        return _objectType;
    }
    
    /**
     * @brief Returns the vector of shape properties of the GameObject.
     * The shape properties vector provides the Interface class with the information
     * it needs to render the GameObject as desired.
     * @return Vector of floats defining the GameObject's shape properties.
     */
    vector<float> getShapeProperties() {
        return _shapeProperties;
    }
     /**
      * @brief Enables the shape properties of a GameObject to be set.
      * The properties of a GameObject may change in accordance with interactions 
      * within the logic layer of the game, and thus must able to be set.
      * @param shapeProperties - vector containing the new shape properties being defined.
      */
    void setShapeProperties(vector<float> shapeProperties) {
        _shapeProperties = shapeProperties;
    }

    
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