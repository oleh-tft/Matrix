#include "Point.h"

istream& operator>>(istream& is, Point& obj)
{
    return is;
}

ostream& operator<<(ostream& os, Point& obj)
{
    cout << "X=" << obj.x << ",Y=" << obj.y;
    return os;
}

Point::Point()
{
    x = y = 0;
}

Point::Point(int X, int Y)
{
    x = X;
    y = Y;
}

Point Point::RandPoint()
{
    return Point(rand() % 10, rand() % 10);
}

