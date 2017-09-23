#ifndef LASER_GENERATOR_H
#define LASER_GENERATOR_H

#include "GameObject.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <memory> // required for smart pointers
#include "ArcSegment.h"
#include "Arc.h"
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

class LaserGenerator : public GameObject
{
public:

//shared_ptr<vector<ArcSegment>> getSegmentsVectorPtr()
//{
//    shared_ptr<vector<ArcSegment>> segmentVector_ptr{new vector<ArcSegment>(_segmentsVector)};
//    return segmentVector_ptr;
//}

//shared_ptr<Arc> getArcPtr()
//{
//    shared_ptr<vector<ArcSegment>> segmentVector_ptr{new vector<ArcSegment>(_segmentsVector)};
//    return segmentVector_ptr;
//}
//
//shared_ptr<LaserGenerator> getPartnerPtr()
//{
//    return _partner_ptr;
//}
int getID()
{
    return _ID;
}

LaserGenerator (float degrees, int ID);

//LaserGenerator (shared_ptr<LaserGenerator> partner_ptr, float degrees);

private:

int _ID;
//shared_ptr<LaserGenerator> _partner_ptr;
//vector<ArcSegment> _segmentsVector;
//Arc _arc = NULL;

};

#endif