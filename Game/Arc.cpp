#include "Arc.h"

Arc::Arc(float angle)
{
    float segmentRotation = angle;
    const float TOTAL_ARC_ANGLE = 45.0f;
    const int NUM_SEGMENTS = 9;
    
//    for (int i = 0; i < NUM_SEGMENTS; i++)
//    {
//        segmentRotation += TOTAL_ARC_ANGLE / NUM_SEGMENTS;
//        _arcSegmentVector.push_back(ArcSegment(segmentRotation));
//    }
}