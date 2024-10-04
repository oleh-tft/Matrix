#pragma once
#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
	friend istream& operator>>(istream& is, Point obj);
	friend ostream& operator<<(ostream& os, Point obj);
public:
	Point();
	Point(int Rand);
	Point(double Rand);
	Point(int X, int Y);

	Point operator+(Point& b);
	Point operator*(Point& b);
	Point operator-(Point& b);
	Point operator/(Point& b);
	Point& operator+=(Point b);
	bool operator<(Point b);
	bool operator==(int b);
};

