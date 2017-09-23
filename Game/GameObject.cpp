#include "GameObject.h"
#include "Game.h"
#include "math.h"
using std::sin;
using std::cos;
using std::pow;
using std::sqrt;
#include <iostream>
using std::cout;
using std::endl;


GameObject::GameObject()
{   }

void GameObject::move(float xOffset, float yOffset)
{
	_objectShape.move(xOffset, yOffset);
}


void GameObject::circularMove(int direction)
{
    // control player movement
	_angle += direction; // positive or negative
    float vecX = cos(_angle*M_PI/90)*Game::PATH_RADIUS;
    float vecY = sin(_angle*M_PI/90)*Game::PATH_RADIUS;
	_xCoord = Game::ORIGIN_X + vecX;
	_yCoord = Game::ORIGIN_Y + vecY;
	_objectShape.setPosition(_xCoord, _yCoord);
    _objectShape.setRotation(_angle*2);
	//cout << _xCoord << " " << _yCoord << " " << _angle <<  endl;
    
    // setup for player bullet movement vecor
    vecX = -vecX/BULLET_SPEED_MODIFIER;
    vecY = -vecY/BULLET_SPEED_MODIFIER;
    _pathVector = sf::Vector2f(vecX, vecY);

}

void GameObject::lineMove()
{
	_xCoord += _pathVector.x;
	_yCoord += _pathVector.y;
	_objectShape.setPosition(_xCoord, _yCoord);
    
    _scale += _scaleFactor;
    _scaleCount++;
    
    if (_scale > 1 && !(_objectType == gameObjectType::LaserGenerator || _objectType == gameObjectType::ArcSegment)) {
        _scale = 1;
    }
    
    sf::Vector2f newSize(_objectWidth*_scale, _objectHeight*_scale);
    _objectShape.setSize(newSize);
    _objectShape.setOrigin(_objectShape.getSize().x/2, _objectShape.getSize().y/2);
    _hitRadius = (_objectShape.getSize().y + _objectShape.getSize().x)/4;

    // Check bullet reaches screen centre
    if (_objectType == gameObjectType::PlayerBullet && (_xCoord >= 395 && _xCoord <= 405 && _yCoord >= 395 && _yCoord <= 405))
    {
        _health = 0;
    }
    
    // Check enemy/enemy bullet/asteroid/laser generator/arc segment goes off the screen
    if ((_objectType == gameObjectType::Enemy || _objectType == gameObjectType::EnemyBullet || _objectType == gameObjectType::Asteriod || _objectType == gameObjectType::LaserGenerator || _objectType == gameObjectType::ArcSegment) && (_xCoord >= 850 || _xCoord <= -50 || _yCoord >= 850 || _yCoord <= -50))
    {
        _health = 0;
    }
}

void GameObject::checkCollisions(vector<shared_ptr<GameObject>> &objectVector)
{
    for (auto element : objectVector)
    {
        if (element->getObjectType() == gameObjectType::PlayerBullet && _objectType == gameObjectType::Enemy)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                _health = 0;
            }
        }
        
        if (element->getObjectType() == gameObjectType::Enemy && _objectType == gameObjectType::PlayerBullet)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
                _health = 0;
        }
        
        if (element->getObjectType() == gameObjectType::Enemy && _objectType == gameObjectType::Player)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
                _health--;
        }
        
        if (element->getObjectType() == gameObjectType::Player && _objectType == gameObjectType::Enemy)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
                _health = 0;
        }
        
        if (element->getObjectType() == gameObjectType::EnemyBullet && _objectType == gameObjectType::Player)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
                _health--;
        }
        
        if (element->getObjectType() == gameObjectType::Player && _objectType == gameObjectType::EnemyBullet)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
                _health = 0;
        }
        
        if (element->getObjectType() == gameObjectType::Asteriod && _objectType == gameObjectType::Player)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                _health--;
            }
        }
        
        if ((element->getObjectType() == gameObjectType::LaserGenerator || element->getObjectType() == gameObjectType::ArcSegment) && _objectType == gameObjectType::Player)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                _health--;
            }
        }
        
        if (element->getObjectType() == gameObjectType::Player && (_objectType == gameObjectType::LaserGenerator || _objectType == gameObjectType::ArcSegment))
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                int ID;
                
                // get ID of element that hit the player
                if (_objectType == gameObjectType::LaserGenerator)
                {
                    shared_ptr<LaserGenerator> laserGen_ptr = std::static_pointer_cast<LaserGenerator>((*this).getptr());
                    ID = laserGen_ptr->getID();
                }
                else
                {
                    shared_ptr<ArcSegment> arcSeg_ptr = std::static_pointer_cast<ArcSegment>((*this).getptr());
                    ID = arcSeg_ptr->getID();
                }
                
                // delete objects with the same ID in vector
                for (int i = 0; i < objectVector.size(); i++)
                {
                    if (objectVector[i]->getObjectType() == gameObjectType::LaserGenerator)
                    {
                        shared_ptr<LaserGenerator> laserGen_ptr = std::static_pointer_cast<LaserGenerator>((*objectVector[i]).getptr());
                        int tempID = laserGen_ptr->getID();
                        
                        if (tempID == ID) {
                            objectVector[i]->setHealth(0);
                        }
                    }
                    
                    if (objectVector[i]->getObjectType() == gameObjectType::ArcSegment)
                    {
                        shared_ptr<ArcSegment> arcSeg_ptr = std::static_pointer_cast<ArcSegment>((*objectVector[i]).getptr());
                        int tempID = arcSeg_ptr->getID();
                        
                        if (tempID == ID) {
                            objectVector[i]->setHealth(0);
                        }
                    }
                }
            }
        }
        
        if (element->getObjectType() == gameObjectType::PlayerBullet && _objectType == gameObjectType::LaserGenerator)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                // delete player bullet
                shared_ptr<PlayerBullet> playerBullet_ptr = std::static_pointer_cast<PlayerBullet>((*element).getptr());
                playerBullet_ptr->setHealth(0);
                
                // delete laserGen
                _health = 0;
                
                // find ID of hit laserGen
                shared_ptr<LaserGenerator> laserGen_ptr = std::static_pointer_cast<LaserGenerator>((*this).getptr());
                int ID = laserGen_ptr->getID();
                
                // delete all arcSegs with the same ID
                for (int i = 0; i < objectVector.size(); i++)
                {
                    shared_ptr<ArcSegment> arcSeg_ptr = std::static_pointer_cast<ArcSegment>((*objectVector[i]).getptr());

                    if (objectVector[i]->getObjectType() == gameObjectType::ArcSegment && arcSeg_ptr->getID() == ID)
                    {
                        objectVector[i]->setHealth(0);
                    }
                }
            }
        }
    }
}

//void GameObject::decrementEnemyBulletCooldown()
//{
//    if (_bulletCooldown > 0)
//        _bulletCooldown--;
//}
//
//void Game::decrementEnemyCooldown()
//{
//    if (_enemyCooldown > 0)
//        _enemyCooldown--;
//}
//
//void Game::decrementAsteriodCooldown()
//{
//    if (_asteriodCooldown > 0)
//        _asteriodCooldown--;
//}