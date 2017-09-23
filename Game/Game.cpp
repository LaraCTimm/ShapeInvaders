#include <SFML/Graphics.hpp>
#include "Game.h"
//#include "GameObject.h"



GameObject Game::spawnGameObject(gameObjectType type) 
{
    switch (type) 
    {
        case gameObjectType::Player:
            return Player();
            
        case gameObjectType::Enemy:
            // Creates enemy spawning at the centr of the screen
            return Enemy(ORIGIN_X, ORIGIN_Y, _GameObjectsVector[0].getPathVector(), _GameObjectsVector[0].getAngle());
            
        case gameObjectType::PlayerBullet:
        {
            // Creates a bullet at the current co-ords of the player
            return PlayerBullet(_GameObjectsVector[0].getXCoord(), _GameObjectsVector[0].getYCoord(), _GameObjectsVector[0].getPathVector(), _GameObjectsVector[0].getAngle());
        }
            
        case gameObjectType::EnemyBullet:
            break;
        case gameObjectType::Astroid:
            break;
        case gameObjectType::Satellite:
            break;
        case gameObjectType::LaserGenerator:
            break;
        default:
            break;
    }
    return GameObject();
}

// Creating an instance of a game automatically spawns a player
// Pass in the previous high score from a text file
Game::Game(int highScore)
{
    // Player becomes first element in _GameObjectsVector
    GameObject obj =  Game::spawnGameObject(gameObjectType::Player); 
    _GameObjectsVector.push_back(obj);
    _bulletCooldown = 0;
}

void Game::movePlayerObject(int direction)
{
	_GameObjectsVector[0].circularMove(direction);
}

void Game::moveLineObject(int objectIndex) 
{
    _GameObjectsVector[objectIndex].lineMove();
    
}

void Game::AddGameObject(gameObjectType type)
{
    GameObject obj =  Game::spawnGameObject(type); 
    _GameObjectsVector.push_back(obj);
}

void Game::ObjectCleanup() 
{
    for (int i = 0; i < _GameObjectsVector.size(); i++)
    {
        // all game objects that aren't of type 'player' use health as a cleanup flag
        if (_GameObjectsVector[i].getHealth() == 0)  
        {
            _GameObjectsVector.erase(_GameObjectsVector.begin() + i);
            i--;
        }
    }
}


void Game::DecrementBulletCooldown()
{
    if (_bulletCooldown>0)
        _bulletCooldown--;
}
