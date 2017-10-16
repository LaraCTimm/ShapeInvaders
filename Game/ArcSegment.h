#ifndef ARC_SEGMENT_H
#define ARC_SEGMENT_H

#include "GameObject.h"
#include "Game.h"

/**
 * @class ArcSegment - represents segments making up arc between laser generator pair
 * Inherits from GameObject class
 */
class ArcSegment : public GameObject
{
public:
    /**
     * @brief Arc segment constructor.
     * @param Angle at which segment is instantiated & along which it moves.
     * @param ID unique to each set of laser generators with joining arcs.
     */
    ArcSegment(float angle, int ID);
    /**
     * @brief Gets ID assigned to the arc segment.
     * @return Segment's ID.
     */
    int getID() { 
        return _ID; 
    }

private:

    int _ID;

};

#endif