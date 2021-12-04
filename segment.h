#pragma once
#include <iostream>
#include <math.h>

using namespace std;

struct point2D
{
    double x;
    double y;
    point2D(double a , double b)
    {
        x =a;
        y = b;
    }
    point2D()
    {
        x = 0;
        y = 0;
    }
};
class segment
{
private:
    point2D startPoint;
    point2D endPoint;
    double angle;
    double length;
public:
    segment()
    {
        angle = 0;
        length =0;
    }
    segment(point2D s , double a , double l)
    {
        startPoint = s;
        angle = a*3.14/180;
        length = l;
        calculateEndPoint();
    }
    void setStartPoint(point2D p)
    {
        startPoint = p;
    }
    point2D getStartPoint()
    {
        return startPoint;
    }
    void setLength(double l)
    {
        length =l;
    }
    double getLength()
    {
        return length;
    }
    void setAngle(double a)
    {
        angle = a;
    }
    double getAngle()
    {
        return angle;
    }
    point2D getEndPoint()
    {
        return endPoint;
    }
    segment resetSegment(point2D sp)
    {
        startPoint = sp;
        angle = 0;
        calculateEndPoint();
        return *this;
    }
    void calculateEndPoint()
    {
        endPoint.x = startPoint.x+(length*cos(angle));
        endPoint.y = startPoint.y+(length*sin(angle));

    }
    void printSegmentInfo()
    {
        cout << "SegmentInfo:\n\tStart Point: ("<<startPoint.x<<","<<startPoint.y<<")\n";
        cout << "\tEnd Point: ("<<endPoint.x<<","<<endPoint.y<<")\n";
        cout << "\tLength: "<<length<<endl;
        cout << "\tAngle: "<<angle*180/3.14<<" (degree)"<<endl;

    }        
};