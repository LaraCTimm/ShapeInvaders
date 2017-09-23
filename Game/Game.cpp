#include <SFML/Graphics.hpp>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Game.h"
#include <iostream>
using std::cout;
using std::endl;

#include <typeinfo>

//#include <iostream>
//#include "GameObject.h"


GameObject Game::spawnGameObject(gameObjectType type, int index) 
{
//    float randAngle;
//    const float _RAND_FLOAT_MAX = 360;//2*M_PI;

    switch (type) 
    {
        case gameObjectType::Player:
            return Player();
            
        case gameObjectType::Enemy:
//            Creates enemy spawning at the center of the screen
            return Enemy(ORIGIN_X, ORIGIN_Y, generateRandomNumber(0, 360));
            
        case gameObjectType::PlayerBullet:
            // Creates a bullet at the current co-ords of the player
            return PlayerBullet(_GameObjectsVector[0].getXCoord(), _GameObjectsVector[0].getYCoord(), _GameObjectsVector[0].getPathVector(), _GameObjectsVector[0].getAngle());
            
        case gameObjectType::EnemyBullet:
            _GameObjectsVector[index].setBulletCooldown(generateRandomNumber(100, 200));
            return EnemyBullet(_GameObjectsVector[index].getXCoord(), _GameObjectsVector[index].getYCoord(), _GameObjectsVector[index].getPathVector(), _GameObjectsVector[index].getAngle(), _GameObjectsVector[index].getScaleCount() );
            
        case gameObjectType::Asteriod:
            return Asteriod(ORIGIN_X, ORIGIN_Y, generateRandomNumber(0, 360));
            break;
        case gameObjectType::Satellite:
            break;
        case gameObjectType::LaserGenerator:
        {
            int ID = 0;
            
//            for(auto element : _GameObjectsVector)
//            {
//                if(element.getObjectType() == gameObjectType::LaserGenerator)
//                {
//                    GameObject* temp = &element;
//                    LaserGenerator* tempGen = dynamic_cast<LaserGenerator*>(temp);
//                    
//                    if(tempGen->getID() > ID)
//                    {
//                        ID = tempGen->getID();
//                        temp = NULL;
//                        tempGen = NULL;
//                    }
//                }
//            }
//            
            ID++;
            
            float angle = generateRandomNumber(0, 360);

            shared_ptr<GameObject> laserGen_ptr1(new LaserGenerator(angle+1, ID));
            
            for(int i=0; i<9; i++)
            {
                angle += 4;
                shared_ptr<GameObject> arcSeg_ptr(new ArcSegment(angle, ID));
                _LaserPointerVector.push_back(arcSeg_ptr);
            }

            _LaserPointerVector.push_back(laserGen_ptr1);
            
            angle += 3;
            
            shared_ptr<GameObject> laserGen_ptr2(new LaserGenerator(angle, ID));
            
            return *laserGen_ptr2;
            break;
            
        }
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
    GameObject obj =  Game::spawnGameObject(gameObjectType::Player, 0); 
    _GameObjectsVector.push_back(obj);
    _bulletCooldown = 0;
    _enemyCooldown = 0;
    _shotFired = false;
    srand (time(0));         // seed randomness for enemy spawning
}

void Game::movePlayerObject(int direction)
{
	_GameObjectsVector[0].circularMove(direction);
}

void Game::moveLineObject(int objectIndex) 
{
    _GameObjectsVector[objectIndex].lineMove();
}

//************************

void Game::movePointerLineObject(int index)
{
    _LaserPointerVector[index]->lineMove();
}

//************************


void Game::AddGameObject(gameObjectType type, int index)
{
    if (type == gameObjectType::LaserGenerator)
    {
        shared_ptr<GameObject> laser_ptr = make_shared<GameObject>(Game::spawnGameObject(type, index));
        _LaserPointerVector.push_back(laser_ptr);
    }
    else
    {
        GameObject obj =  Game::spawnGameObject(type, index); 
        _GameObjectsVector.push_back(obj);
    }
    
    
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


void Game::decrementBulletCooldowns()
{
    for (int i = 0; i < _GameObjectsVector.size(); i++)
    {
        if (_GameObjectsVector[i].getObjectType() == gameObjectType::Enemy)
        {
            _GameObjectsVector[i].decrementBulletCooldown();
            
            if(_GameObjectsVector[i].getBulletCooldown() <= 0)
            {
                AddGameObject(gameObjectType::EnemyBullet, i);
            }
        }
    }
}

void Game::decrementEnemyCooldown()
{
    if (_enemyCooldown > 0)
        _enemyCooldown--;
}

void Game::decrementAsteriodCooldown()
{
    if (_asteriodCooldown > 0)
        _asteriodCooldown--;
}

void Game::CheckCollisions() 
{
    for (int i = 0; i < _GameObjectsVector.size(); i++)
    {
        _GameObjectsVector[i].checkCollisions(_GameObjectsVector);
    }
}

float Game::generateRandomNumber(float min, float max)
{
    float randomNumber = min + float(rand())/float(RAND_MAX/(max-min));
    cout << randomNumber << endl;
    return randomNumber;
}
