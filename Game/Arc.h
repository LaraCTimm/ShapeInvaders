#ifndef ARC_H
#define ARC_H

#include "ArcSegment.h"
#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;

class Arc
{
public:

vector<ArcSegment> getArcSegmentVector()
{
    return _arcSegmentVector;
}

Arc(float angle);
Arc();

private:

vector<ArcSegment> _arcSegmentVector;

};

#endif