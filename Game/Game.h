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
#include "Satellite.h"
#include "FileReader.h"
#include "Interface.h"
#include "keyboardInput.h"

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

class Game
{
public:

    static constexpr float ORIGIN_X = 400.0f;
    static constexpr float ORIGIN_Y = 400.0f;
    static constexpr float PLAYER_RADIUS = 300.0f;
    static constexpr float LIFE_RECT_SIZE = 30.0f;

    /**
     * @brief Game constructor.
     * Responsible for game creation, initialising of all objects (including the game
     * interface) and variables to do with the logic layer of the game.
     * @param integer - Required to launch the SFML window.
     */
    Game(int integer);

    /**
     * @brief Responsible for spawning new GameObjects.
     * New objects are spawned using the spawnGameObject function and added to the 
     * vector containing all existing GameObjects.
     * @param type - type of GameObject to be added.
     * @param index - integer indicating which object a bullet must be fired from.
     */
    void AddGameObject(gameObjectType type, int index);
    
    /**
     * @brief Moves player object circularly upon user input.
     * @param direction - integer direction which is either positive or negative 1.
     */
    void MovePlayerObject(int direction);
    
    /**
     * @brief Moves non-player objects with linear movement patterns.
     * @param objectIndex - integer index of object to be moved.
     */
    void MoveLineObject(int objectIndex);

    /**
     * @brief Checks for collisions between all objects.
     */
    void CheckCollisions();
    /**
     * @brief Deletes objects from vector with zero health remaining.
     */
    void ObjectCleanup();

    /**
     * @brief Checks of the player was destroyed, indicating game over. 
     */
    void CheckGameOver();
    
    /**
     * @brief Generate a random number between a minimum and maximum value.
     * @param min - float minimum value.
     * @param max - float maximum value.
     * @return Random float in the range min to max.
     */
    float GenerateRandomNumber(float min, float max);
    
    /**
     * @brief Check if the current score exceeds the high score.
     */
    void CheckScoreStatus();

    /**
     * @brief Accessor for the vector containing all existing GameObjects.
     * @return Vector containing shared pointers to existing game objects.
     */
     
    vector<shared_ptr<GameObject>> getGameObjectsVector() {
        return _GameObjectsVector;
    }

    //void setGameObjectsVector(const vector<shared_ptr<GameObject>> newGameObjectsVector) {
    //    _GameObjectsVector = newGameObjectsVector;
    //}
    //
    //shared_ptr<int> getScore() {
    //    return _score;
    //}
    //
    //void setScore(const int newScore) {
    //    shared_ptr<int> int_ptr(new int(newScore));
    //    _score = int_ptr;
    //}


    //int getEnemyCooldown() {
    //    return _enemyCooldown;
    //}
    //
    //void setEnemyCooldown(const int newEnemyCooldown) {
    //    _enemyCooldown = newEnemyCooldown;
    //}
    //
    //int getAsteriodCooldown() {
    //    return _asteriodCooldown;
    //}
    //
    //void setAsteriodCooldown(const int newAsteriodCooldown) {
    //    _asteriodCooldown = newAsteriodCooldown;
    //}
    //
    //bool getShotFired() {
    //    return _shotFired;
    //}
    //
    //void setShotFired(const bool newShotFired) {
    //    _shotFired = newShotFired;
    //}

    //shared_ptr<int> getHighScore(){
    //    return _highScore;
    //}
    //
    //void setHighScore(int highScore) {
    //    _highScore = make_shared<int>(highScore);
    //}

    //////////////////////////////////////////////////////


private:
    vector<shared_ptr<GameObject>> _GameObjectsVector;
    shared_ptr<GameObject> _player_ptr;
    vector<sf::RectangleShape> _livesVector;
    shared_ptr<int> _score;
    shared_ptr<int> _highScore;
    sf::Clock _clock;
    float _enemyCooldown;
    float _asteriodCooldown;
    float _laserGeneratorCooldown;
    float _satelliteCooldown;
    bool _shotFired;
    bool _inGame;
    Interface _interface;
    int _gameState;
    
    /**
     * @brief Initialises all variables needed at game start.
     */
    void InitialiseGame();
    
    /**
     * @brief Handles the states of the game.
     * Gameloop is responsible for determining the game state and instructing the interface 
     * as well as the game logic to function accordingly. Gameloop is the main function
     * controlling the game.
     */
    void GameLoop();
    
    /**
     * @brief Checks if the game state must be updated depending on user input.
     * The function is responsible for the translation between what is received from
     * the interface as user input and the corresponding response in the game during the
     * splashscreen and endscreen game states.
     * @param keysPressed - a vector of enumeration values which allow for separation
     * of the logic and interface of the game.
     */
    void CheckGameState(vector<keyboardInput> keysPressed);
    
    /**
     * @brief Is responsible for handling the interaction of user input and game logic 
     * while the game is being played. 
     * The function translates user inputs into game functionality while in game. It 
     * triggers the movement of all non-player objects, collision detection and
     * object cleanup.
     * @param keysPressed
     */
    void Update(vector<keyboardInput> keysPressed);
    
    /**
     * @brief Instructs the interface to render all objects after the game is updated.
     */
    void Render();

    /**
     * @brief Function responsible for the creation of new GameObjects.
     * @param type - enumeration determining the type of object to be created.
     * @param index - integer indicating which object a bullet must be fired from.
     * @return A shared pointer to a GameObject.
     */
    shared_ptr<GameObject> SpawnGameObject(gameObjectType type, int index);
    
    /**
     * @brief Decrements cooldown variables for randomly spawning objects.
     */
    void DecrementCooldowns();
    
    /**
     * @brief  Triggers creation of cooled down objects, resets cooldown variables.
     */
    void CreateGameObjects();
    
    /**
     * @brief Set new high score.
     * High score is stored in a text file and carries over from game to game.
     */
    void SetNewHighScore();

};

#endif