#include "GameObject.h"
#include "Game.h"

GameObject::GameObject()
: _pathVector{0.0f,0.0f}
{  
    
}

//void GameObject::move(float xOffset, float yOffset)
//{
//	_objectShape.move(xOffset, yOffset);
//}


void GameObject::circularMove(int direction)
{   }

void GameObject::lineMove()
{
	_xCoord += _pathVector[0];
	_yCoord += _pathVector[1];
	//_objectShape.setPosition(_xCoord, _yCoord);
    
    _scale += _scaleFactor;
    _scaleCount++;
    
    if (_scale > 1 && !(_objectType == gameObjectType::LaserGenerator || _objectType == gameObjectType::ArcSegment)) {
        _scale = 1;
    }
//    _objectWidth =_objectWidth*_scale;
//    _objectHeight =_objectHeight*_scale;
    //sf::Vector2f newSize(_objectWidth*_scale, _objectHeight*_scale);
    //_objectShape.setSize(newSize);
    //_objectShape.setOrigin(_objectShape.getSize().x/2, _objectShape.getSize().y/2);
    //_hitRadius = (_objectShape.getSize().y + _objectShape.getSize().x)/4;
    
    _hitRadius = (_objectHeight*_scale + _objectWidth*_scale)/4; 
    
    checkInBounds();
}

void GameObject::checkInBounds()
{
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

int GameObject::checkCollisions(vector<shared_ptr<GameObject>> &objectVector)
{
    int pointsWon = 0;
    
    for (auto element : objectVector)
    {
        if (element->getObjectType() == gameObjectType::PlayerBullet && _objectType == gameObjectType::Enemy)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                _health = 0;
                pointsWon += _points;
                shared_ptr<PlayerBullet> playerBullet_ptr = std::static_pointer_cast<PlayerBullet>((*element).getptr());
                playerBullet_ptr->setHealth(0);

            }
        }
        
        if (element->getObjectType() == gameObjectType::Enemy && _objectType == gameObjectType::Player)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                _health--;
                shared_ptr<Enemy> enemy_ptr = std::static_pointer_cast<Enemy>((*element).getptr());
                enemy_ptr->setHealth(0);
            }   
        }
        
        if (element->getObjectType() == gameObjectType::EnemyBullet && _objectType == gameObjectType::Player)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                _health--;
                shared_ptr<EnemyBullet> enemyBullet_ptr = std::static_pointer_cast<EnemyBullet>((*element).getptr());
                enemyBullet_ptr->setHealth(0);
            }
        }
        
        if (element->getObjectType() == gameObjectType::Asteriod && _objectType == gameObjectType::Player)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                _health--;
                shared_ptr<Asteriod> asteriod_ptr = std::static_pointer_cast<Asteriod>((*element).getptr());
                asteriod_ptr->setHealth(0);
            }
        }
        
        if (element->getObjectType() == gameObjectType::Asteriod && _objectType == gameObjectType::PlayerBullet)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                _health = 0;
            }
        }
        
        if (element->getObjectType() == gameObjectType::ArcSegment && _objectType == gameObjectType::PlayerBullet)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                _health = 0;
            }
        }
        
        if (element->getObjectType() == gameObjectType::Player && (_objectType == gameObjectType::LaserGenerator || _objectType == gameObjectType::ArcSegment))
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                shared_ptr<Player> player_ptr = std::static_pointer_cast<Player>((*element).getptr());
                player_ptr->setHealth(player_ptr->getHealth() - 1);
                
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
                pointsWon += _points;

                
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
        
        if (element->getObjectType() == gameObjectType::Satellite && _objectType == gameObjectType::PlayerBullet)
        {
            float distance = sqrt(pow(element->getXCoord()-_xCoord,2) + pow(element->getYCoord()-_yCoord,2));
            if (distance <= element->getHitRadius()+_hitRadius)
            {
                _health = 0;
                shared_ptr<Satellite> satellite_ptr = std::static_pointer_cast<Satellite>((*element).getptr());
                
                satellite_ptr->setHealth(0);
                pointsWon += _points;
                
                int ID = satellite_ptr->getID();
                int tempID;
                bool IDmatch = false;
                
                for (int i = 0; i < objectVector.size(); i++)
                { 
                    if (objectVector[i]->getObjectType() == gameObjectType::Satellite)
                    {
                        shared_ptr<Satellite> satellite_ptr2 = std::static_pointer_cast<Satellite>((*objectVector[i]).getptr());
                        tempID = satellite_ptr2->getID();
                        if (ID == tempID && satellite_ptr2->getHealth() > 0)
                        {
                            IDmatch = true;
                        }
                    }
                }
                
                if (!IDmatch)
                {
                    shared_ptr<Player> player_ptr = std::static_pointer_cast<Player>((*objectVector[0]).getptr());
                    player_ptr->UpgradeGun();
                }
            }
        }
    }
    return pointsWon;
}
