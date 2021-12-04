#pragma once 
#include "segment.h"

class robot
{
private:
    int segmentNumber;
    segment roboSegments[40];
public:
    robot()
    {
        segmentNumber = 0;
    }
    void addSegment(point2D p , double a , double l)
    {
        roboSegments[segmentNumber] = segment(p,a,l);
        segmentNumber++;
    }   
    void removeSegment()
    {
        roboSegments[segmentNumber] = segment();
        segmentNumber--;
    }
    void resetRobot()
    {
        roboSegments[0] = roboSegments[0].resetSegment(point2D(0,0));

        for(int i=1 ; i<segmentNumber ; i++)
        {
            point2D p = roboSegments[i-1].getEndPoint();
            roboSegments[i] = roboSegments[1].resetSegment(p);
        }
    }
    void printRobotSegments()
    {
        for(int i=0 ; i<segmentNumber ; i++)
        {
            roboSegments[i].printSegmentInfo();
        }
    }
};