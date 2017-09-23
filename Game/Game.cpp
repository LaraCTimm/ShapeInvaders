#include <SFML/Graphics.hpp>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Game.h"
#include <iostream>
using std::cout;
using std::endl;

//#include <iostream>
#include "GameObject.h"

// Pass in the previous high score from a text file
Game::Game(int highScore)
{
    // Player becomes first element in _GameObjectsVector
    shared_ptr<GameObject> obj_ptr = Game::spawnGameObject(gameObjectType::Player, 0);
    _GameObjectsVector.push_back(obj_ptr);
    //_bulletCooldown = 0;
    _enemyCooldown = 10;
    _asteriodCooldown = 400;
    _laserGeneratorCooldown = 800;
    _shotFired = false;
    _generatorFired = false;
    srand (time(0));         // seed randomness for enemy spawning
}

shared_ptr<GameObject> Game::spawnGameObject(gameObjectType type, int index) 
{
    switch (type) 
    {
        case gameObjectType::Player:
            return shared_ptr<GameObject>(new Player());
            
        case gameObjectType::Enemy:
//            Creates enemy spawning at the center of the screen
            return shared_ptr<GameObject>(new Enemy(ORIGIN_X, ORIGIN_Y, generateRandomNumber(0, 360)));
            
        case gameObjectType::PlayerBullet:
            // Creates a bullet at the current co-ords of the player
            return shared_ptr<GameObject>(new PlayerBullet(_GameObjectsVector[0]->getXCoord(), _GameObjectsVector[0]->getYCoord(), _GameObjectsVector[0]->getPathVector(), _GameObjectsVector[0]->getAngle()));
            
        case gameObjectType::EnemyBullet:
            return shared_ptr<GameObject>(new EnemyBullet(_GameObjectsVector[index]->getXCoord(), _GameObjectsVector[index]->getYCoord(), _GameObjectsVector[index]->getPathVector(), _GameObjectsVector[index]->getAngle(), _GameObjectsVector[index]->getScaleCount() ));
            
        case gameObjectType::Asteriod:
            return shared_ptr<GameObject>(new Asteriod(ORIGIN_X, ORIGIN_Y, _GameObjectsVector[0]->getAngle()));
            
        case gameObjectType::Satellite:
            break;
        case gameObjectType::LaserGenerator:
        {
            int ID = 0;
            
            for(auto element : _GameObjectsVector)
            {
                if(element->getObjectType() == gameObjectType::LaserGenerator)
                {
                    shared_ptr<LaserGenerator> laserGen_ptr = std::static_pointer_cast<LaserGenerator>((*element).getptr());

                    if(laserGen_ptr->getID() > ID)
                    {
                        ID = laserGen_ptr->getID();
                    }
                }
            }
            
            ID++;
            float angle = generateRandomNumber(0, 360);
            shared_ptr<GameObject> laserGen_ptr1(new LaserGenerator(angle + 1, ID));
            
            for(int i = 0; i < 7; i++)
            {
                angle += 4;
                shared_ptr<GameObject> arcSeg_ptr(new ArcSegment(angle, ID));
                _GameObjectsVector.push_back(arcSeg_ptr);
            }

            _GameObjectsVector.push_back(laserGen_ptr1);
            
            angle += 4;
            shared_ptr<GameObject> laserGen_ptr2(new LaserGenerator(angle - 1, ID));
            
            return laserGen_ptr2;
        }
        
        default:
            break;
    }
    return shared_ptr<GameObject>();
} 



void Game::movePlayerObject(int direction)
{
	_GameObjectsVector[0]->circularMove(direction);
}

void Game::moveLineObject(int objectIndex) 
{
    _GameObjectsVector[objectIndex]->lineMove();
}

void Game::AddGameObject(gameObjectType type, int index)
{
    shared_ptr<GameObject> object_ptr = Game::spawnGameObject(type, index);
    _GameObjectsVector.push_back(object_ptr);
}

void Game::ObjectCleanup() 
{
    for (int i = 0; i < _GameObjectsVector.size(); i++)
    {
        // all game objects use health as a cleanup flag
        if (_GameObjectsVector[i]->getHealth() == 0)  
        {
            _GameObjectsVector.erase(_GameObjectsVector.begin() + i);
            i--;
        }
    }
}

//// should all be in individual files

void Game::DecrementCooldowns()
{
    for (int i = 0; i < _GameObjectsVector.size(); i++)
    {
        if (_GameObjectsVector[i]->getObjectType() == gameObjectType::Enemy)
        {
            shared_ptr<Enemy> enemy_ptr = std::static_pointer_cast<Enemy>((*_GameObjectsVector[i]).getptr());
            enemy_ptr->decrementEnemyBulletCooldown(); 
          
            if (enemy_ptr->getBulletCooldown() <= 0)
            {
                AddGameObject(gameObjectType::EnemyBullet, i);
                enemy_ptr->setBulletCooldown(generateRandomNumber(100,200));
            }
        }
    }
    
    if (_enemyCooldown > 0) {
        _enemyCooldown--;
    }
    
    if (_asteriodCooldown > 0) {
        _asteriodCooldown--;
    }
    
     if (_laserGeneratorCooldown > 0) {
        _laserGeneratorCooldown--;
    }
}

//void Game::SpawnGameObjects()
//{
//    if (getEnemyCooldown() <= 0)
//    {
//        AddGameObject(gameObjectType::Enemy, 0);
//        setEnemyCooldown(generateRandomNumber(75.0f, 150.0f));
//    }
//            
//    if (getAsteriodCooldown() <= 0)
//    {
//        AddGameObject(gameObjectType::Asteriod, 0);
//        setAsteriodCooldown(generateRandomNumber(100.0f, 150.0f));
//    }
//}

void Game::SpawnGameObjects()
{
    if (_enemyCooldown <= 0)
    {
        AddGameObject(gameObjectType::Enemy, 0);
        _enemyCooldown = generateRandomNumber(75.0f, 150.0f);
    }
            
    if (_asteriodCooldown <= 0)
    {
        AddGameObject(gameObjectType::Asteriod, 0);
        _asteriodCooldown = generateRandomNumber(100.0f, 150.0f);
    }
    
    if (_laserGeneratorCooldown <= 0)
    {
        AddGameObject(gameObjectType::LaserGenerator, 0);
        _laserGeneratorCooldown = generateRandomNumber(350.0f, 400.0f);
    }
}


void Game::CheckCollisions() 
{
    for (int i = 0; i < _GameObjectsVector.size(); i++)
    {
        _GameObjectsVector[i]->checkCollisions(_GameObjectsVector);
    }
}

float Game::generateRandomNumber(float min, float max)
{
    float randomNumber = min + float(rand())/float(RAND_MAX/(max-min));
    cout << randomNumber << endl;
    return randomNumber;
}
