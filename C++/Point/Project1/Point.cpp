#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
#include "Point.h"

int Point::count = 0;

Point::Point(int x, int y)
	:x(x), y{ y }
{
	//this->x = x;
	//this->y = y;
	name = 'A' + count;// 'A' + 1 = 'B'
	++count;


}

Point::Point(int x)
	: Point(x, 0)
{
}

void Point::print() const
{
	cout << name <<" (" << x << ", " << y << ")\t";
}

int Point::getCountPoints()
{
	return count;
}

double Point::distance(const Point& point1, const Point& point2)
{
	return sqrt( pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

int Point::compair_distance(const Point& point0, Point& point1, const Point& point2)
{
	int a = distance(point0, point1);
	int b = distance(point0, point2);

	cout << a << endl;
	cout << b << endl;

	if (a == b)
		return 0;
	if (a > b)
		return 1;
	if (a < b)
		return -1;
}

Point Point::operator + (const Point& other)
{
	int result_x = this->x + other.x;
	int result_y = this->y + other.y;
	Point tmp(result_x, result_y);
	return tmp;
}

bool Point::operator == (const Point& other)
{
	return this->x == other.x && this->y == other.y;
}

bool Point::operator != (const Point& other)
{
	return !(this->x == other.x && this->y == other.y);
}

Point& Point::operator-(int a)
{
	int result_x = -this->x;
	int result_y = -this->y;
	Point tmp(result_x, result_y);

	return tmp;
}

Point& Point::operator+=(int value)
{
	this->x += value;
	this->y += value;

	return *this;
}

Point& Point::operator*=(int value)
{
	this->x *= value;
	this->y *= value;

	return *this;
}





