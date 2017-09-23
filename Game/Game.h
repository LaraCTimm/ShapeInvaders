#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Enemy.h"
#include <vector>
using std::vector;


//////////////////////////////////////////////////////

class Game
{
public:

static constexpr float ORIGIN_X = 400.f;
static constexpr float ORIGIN_Y = 400.f;
static constexpr float PATH_RADIUS = 300.f;

// Accessors and Mutators ----------------------------

vector<GameObject> getGameObjectsVector() {
    return _GameObjectsVector;
}

void setGameObjectsVector(const std::vector<GameObject> newGameObjectsVector) {
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

int getBulletCooldown() {
    return _bulletCooldown;
}

void setBulletCooldown(const int newBulletCooldown) {
    _bulletCooldown = newBulletCooldown;
}

//---------------------------------------------------

// Constructor
Game(int highScore);

// Create a game object
GameObject spawnGameObject(gameObjectType type);

// Moves the player in a circular arc
void movePlayerObject(int direction);

// Moves objects that travel in a straight line
void moveLineObject(int objectIndex);

// Adds game object to vector be rendered
void AddGameObject(gameObjectType type);

// Delete objects from vector that are no longer needed
void ObjectCleanup();

void DecrementBulletCooldown();


//////////////////////////////////////////////////////
    
private:
    vector<GameObject> _GameObjectsVector;
    int _score;
    sf::Clock _clock;
    int _bulletCooldown;
    
};

#endif