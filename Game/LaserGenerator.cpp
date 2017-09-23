#include <LaserGenerator.h>

LaserGenerator::LaserGenerator (float degrees, int ID) : GameObject()
{
    _xCoord = Game::ORIGIN_X;
	_yCoord = Game::ORIGIN_Y;
    _angle = degrees;
    _objectWidth = 35;
    _objectHeight = 35;
    _hitRadius = (_objectWidth + _objectHeight)/4;
//    _bulletCooldown = 25;
    _health = 1;
    _points = 10;
    _scale = 0.2;
    _scaleFactor = (1 - _scale) / Game::PATH_RADIUS;
    _scaleCount = 0;
    _objectType = gameObjectType::LaserGenerator;
    
    float vecX = cos(_angle*M_PI/90);
    float vecY = sin(_angle*M_PI/90);
    
    const float SPEED_MULTIPLIER = 1.0f;
    
    vecX = -vecX * SPEED_MULTIPLIER;
    vecY = -vecY * SPEED_MULTIPLIER;
    _pathVector = sf::Vector2f(vecX, vecY);
    
    // Create rectangle
    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
    
    // Set attributes
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(sf::Color::Cyan);
    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));
    rectangle.setRotation(_angle*2);
    rectangle.setPosition(_xCoord, _yCoord);
    setObjectShape(rectangle);
    
    _ID = ID;
    
//    float segmentRotation = _angle;
//    const float TOTAL_ARC_ANGLE = 45.0f;
//    const int NUM_SEGMENTS = 9;
    
//    Arc arc(degrees);
//    _arc = arc;
    
//    for (int i = 0; i < NUM_SEGMENTS; i++)
//    {
//        segmentRotation += TOTAL_ARC_ANGLE / NUM_SEGMENTS;
//        //_segmentsVector.push_back(ArcSegment(segmentRotation));
//    }
    
//    shared_ptr<LaserGenerator> thisGenerator{this};
//    shared_ptr<LaserGenerator> partner_ptr{new LaserGenerator(thisGenerator, segmentRotation + TOTAL_ARC_ANGLE / NUM_SEGMENTS)};
//    _partner_ptr = partner_ptr;
    
}

//LaserGenerator::LaserGenerator (shared_ptr<LaserGenerator> partner_ptr, float degrees) : GameObject()
//{
//    _xCoord = Game::ORIGIN_X;
//	_yCoord = Game::ORIGIN_Y;
//    _angle = degrees;
//    _objectWidth = 35;
//    _objectHeight = 35;
//    _hitRadius = (_objectWidth + _objectHeight)/4;
////    _bulletCooldown = 25;
//    _health = 1;
//    _points = 10;
//    _scale = 0.2;
//    _scaleFactor = (1 - _scale) / Game::PATH_RADIUS;
//    _scaleCount = 0;
//    _objectType = gameObjectType::Asteriod;
//    
//    float vecX = cos(_angle*M_PI/90);
//    float vecY = sin(_angle*M_PI/90);
//    
//    const float SPEED_MULTIPLIER = 1.0f;
//    
//    vecX = -vecX * SPEED_MULTIPLIER;
//    vecY = -vecY * SPEED_MULTIPLIER;
//    _pathVector = sf::Vector2f(vecX, vecY);
//    
//    // Create rectangle
//    sf::RectangleShape rectangle(sf::Vector2f(_scale*_objectWidth, _scale*_objectHeight));
//    
//    // Set attributes
//    rectangle.setOutlineThickness(2);
//    rectangle.setOutlineColor(sf::Color::Black);
//    rectangle.setFillColor(sf::Color::Cyan);
//    rectangle.setOrigin(sf::Vector2f(_scale*_objectWidth/2, _scale*_objectHeight/2));
//    rectangle.setRotation(_angle*2);
//    rectangle.setPosition(_xCoord, _yCoord);
//    setObjectShape(rectangle);
//    
//    _partner_ptr = partner_ptr;
//    //_segmentsVector = *_partner_ptr->getSegmentsVectorPtr();
//    
//    
//    Arc arc(1);
//    _arc = arc;
//}