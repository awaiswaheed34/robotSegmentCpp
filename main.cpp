#include <iostream>

using namespace std;


struct point2D
{
    double x;
    double y;
    point2D(double a, double b)
    {
        x = a;
        y = b;
    }  // constructor with parameter
    point2D()
    {
        x = 0;
        y = 0;
    }   // constuctor default
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
        length = 0;
    } 
    segment(point2D s, double a, double l)
    {
        startPoint = s;
        angle = a * 3.14 / 180;  // to radian
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
        length = l;
    }
    double getLength()
    {
        return length;
    }
    void setAngle(double a)
    {
        angle = a * 3.14 / 180;
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
        endPoint.x = startPoint.x + (length * cos(angle));
        endPoint.y = startPoint.y + (length * sin(angle));

    }
    void printSegmentInfo()
    {
        cout << "SegmentInfo:\n\tStart Point: (" << startPoint.x << "," << startPoint.y << ")\n";
        cout << "\tEnd Point: (" << endPoint.x << "," << endPoint.y << ")\n";
        cout << "\tLength: " << length << endl;
        cout << "\tAngle: " << angle * 180 / 3.14 << " (degree)" << endl;

    }
};


class robot
{
private:
    int segmentNumber;
    segment* roboSegments;
public:
    robot(int seg)
    {
        segmentNumber = 0;
        roboSegments = new segment[seg];
    }
    void addSegment(point2D p, double a, double l)
    {
        roboSegments[segmentNumber] = segment(p, a, l);
        segmentNumber++;
    }
    void removeSegment()
    {
        roboSegments[segmentNumber] = segment();
        segmentNumber--;
    }
    void resetRobot()
    {
        roboSegments[0] = roboSegments[0].resetSegment(point2D(0, 0));

        for (int i = 1; i < segmentNumber; i++)
        {
            point2D p = roboSegments[i - 1].getEndPoint();
            roboSegments[i] = roboSegments[1].resetSegment(p);
        }
    }

    void printRobotSegments()
    {
        for (int i = 0; i < segmentNumber; i++)
        {
            roboSegments[i].printSegmentInfo();
        }
    }
};

int main()
{
	robot robo(10);
	robo.addSegment(point2D(12,3),33,5);
	robo.addSegment(point2D(55,3),35,5);
	robo.printRobotSegments();
	robo.resetRobot();
	robo.printRobotSegments();
	robo.addSegment(point2D(55, 5), 90, 12);
	robo.addSegment(point2D(66, 3), 80, 8);
	robo.removeSegment();
	robo.printRobotSegments();
	return 0;
}