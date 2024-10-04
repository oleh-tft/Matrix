#include "Point.h"

istream& operator>>(istream& is, Point obj)
{
    return is;
}

ostream& operator<<(ostream& os, Point obj)
{
    cout << "X=" << obj.x << ",Y=" << obj.y;
    return os;
}

Point::Point()
{
    x = y = 0;
}

Point::Point(int Rand)
{
    x = Rand;
    y = Rand + 10;
}

Point::Point(double Rand):Point((int)Rand)
{
}

Point::Point(int X, int Y)
{
    x = X;
    y = Y;
}

Point Point::operator+(Point& b)
{
    return Point(x + b.x, y + b.y);
}

Point Point::operator*(Point& b)
{
    return Point(x * b.x, y * b.y);
}

Point Point::operator-(Point& b)
{
    return Point(x - b.x, y - b.y);
}

Point Point::operator/(Point& b)
{
    return Point(x / b.x, y / b.y);
}

Point& Point::operator+=(Point b)
{
    x += b.x;
    y += b.y;
    return *this;
}

bool Point::operator<(Point b)
{
    return x + y < b.x + b.y;
}

bool Point::operator==(int b)
{
    return x == b || y == b;
}
