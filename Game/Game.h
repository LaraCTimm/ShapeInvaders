#ifndef GAME_H
#define GAME_H

#include "GameObject.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Asteriod.h"
#include "LaserGenerator.h"
#include "ArcSegment.h"
#include "FileReader.h"

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>
#include <iostream>
#include <vector>
#include <memory>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;
//using std::unique_ptr;
//using std::make_unique;
//using std::iterator;


//////////////////////////////////////////////////////

class Game
{
public:

static constexpr float ORIGIN_X = 400.0f;
static constexpr float ORIGIN_Y = 400.0f;
static constexpr float PLAYER_RADIUS = 300.0f;
static constexpr float SCREEN_HEIGHT = 800.0f;
static constexpr float SCREEN_WIDTH = 800.0f;
static constexpr float LIFE_RECT_SIZE = 30.0f;



// Accessors and Mutators ----------------------------

vector<shared_ptr<GameObject>> getGameObjectsVector() {
    return _GameObjectsVector;
}

void setGameObjectsVector(const vector<shared_ptr<GameObject>> newGameObjectsVector) {
    _GameObjectsVector = newGameObjectsVector;
}

vector<sf::RectangleShape> getLivesVector() {
    return _livesVector;
}

shared_ptr<int> getScore() {
    return _score;
}

//void setScore(const int newScore) {
//    shared_ptr<int> int_ptr(new int(newScore));
//    _score = int_ptr;
//}

sf::Clock getClock() {
    return _clock;
}

void restartClock() {
    _clock.restart();
}

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

sf::Text getCurrentScoreText() {
    return _currentScoreText;
}

sf::Text getHighScoreText() {
    return _highScoreText;
}

shared_ptr<int> getHighScore(){
    return _highScore;
}
//
//void setHighScore(int highScore) {
//    _highScore = make_shared<int>(highScore);
//}

///////// should be in other classes ////////

//---------------------------------------------------

// Constructor
Game(int highScore);

// Create a game object
shared_ptr<GameObject> SpawnGameObject(gameObjectType type, int index);

// Moves the player in a circular arc
void MovePlayerObject(int direction);

// Moves objects that travel in a straight line
void MoveLineObject(int objectIndex);

// Adds game object to vector be rendered
void AddGameObject(gameObjectType type, int index);

// Delete objects from vector that are no longer needed
void ObjectCleanup();

void DecrementCooldowns();

void CreateGameObjects();

void CheckCollisions();

float GenerateRandomNumber(float min, float max);

void CheckScoreStatus();

void SetNewHighScore();


//////////////////////////////////////////////////////


private:
    vector<shared_ptr<GameObject>> _GameObjectsVector;
    vector<sf::RectangleShape> _livesVector;
    shared_ptr<int> _score;
    shared_ptr<int> _highScore;
    sf::Text _highScoreText;
    sf::Text _currentScoreText;
    sf::Clock _clock;
    //int _bulletCooldown;
    float _enemyCooldown;
    float _asteriodCooldown;
    float _laserGeneratorCooldown;
    bool _shotFired;
    


    
};

#endif