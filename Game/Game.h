#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Asteriod.h"
#include "LaserGenerator.h"
#include "ArcSegment.h"
#include <vector>
#include <memory> // required for smart pointers
using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

using std::iterator;


//////////////////////////////////////////////////////

class Game
{
public:

static constexpr float ORIGIN_X = 400.0f;
static constexpr float ORIGIN_Y = 400.0f;
static constexpr float PATH_RADIUS = 300.0f;

// Accessors and Mutators ----------------------------

//vector<shared_ptr<GameObject>> getLaserPointerVector() {
//    return _LaserPointerVector;
//}




vector<shared_ptr<GameObject>> getGameObjectsVector() {
    return _GameObjectsVector;
}

void setGameObjectsVector(const vector<shared_ptr<GameObject>> newGameObjectsVector) {
    _GameObjectsVector = newGameObjectsVector;
}

int getScore() {
    return _score;
}

void setScore(const int newScore) {
    _score = newScore;
}

sf::Clock getClock() {
    return _clock;
}

void restartClock() {
    _clock.restart();
}

///////// should be in other classes ////////
//int getBulletCooldown() {
//    return _bulletCooldown;
//}
//
//void setBulletCooldown(const int newBulletCooldown) {
//    _bulletCooldown = newBulletCooldown;
//}
//
int getEnemyCooldown() {
    return _enemyCooldown;
}

void setEnemyCooldown(const int newEnemyCooldown) {
    _enemyCooldown = newEnemyCooldown;
}

int getAsteriodCooldown() {
    return _asteriodCooldown;
}

void setAsteriodCooldown(const int newAsteriodCooldown) {
    _asteriodCooldown = newAsteriodCooldown;
}

bool getShotFired() {
    return _shotFired;
}

void setShotFired(const bool newShotFired) {
    _shotFired = newShotFired;
}

bool getGeneratorFired() {
    return _generatorFired;
}

void setGeneratorFired(const bool newGeneratorFired) {
    _generatorFired = newGeneratorFired;
}

///////// should be in other classes ////////

//---------------------------------------------------

// Constructor
Game(int highScore);

// Create a game object
shared_ptr<GameObject> spawnGameObject(gameObjectType type, int index);

// Moves the player in a circular arc
void movePlayerObject(int direction);

// Moves objects that travel in a straight line
void moveLineObject(int objectIndex);

// Adds game object to vector be rendered
void AddGameObject(gameObjectType type, int index);

// Delete objects from vector that are no longer needed
void ObjectCleanup();

void DecrementCooldowns();

void SpawnGameObjects();

void CheckCollisions();

float generateRandomNumber(float min, float max);


//////////////////////////////////////////////////////


private:
    vector<shared_ptr<GameObject>> _GameObjectsVector;
    int _score;
    sf::Clock _clock;
    //int _bulletCooldown;
    float _enemyCooldown;
    float _asteriodCooldown;
    bool _shotFired;
    bool _generatorFired;

    


    
};

#endif