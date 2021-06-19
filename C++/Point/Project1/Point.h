#pragma once
class Point
{
public:
	
	Point(int x, int y);
	Point(int x = 0);
	//Point() = default; // {}
	void print() const;
	static int getCountPoints(); // static  method doesn  not receive THIS
	static double distance(const Point& point1, const Point& point2);
	static int compair_distance(const Point& point0, Point& point1, const Point& point2);
	Point operator + (const Point& other);
	bool operator == (const Point& other);
	bool operator != (const Point& other);

	Point & operator -(int a);

	Point &operator += (int value);
	Point& operator *= (int value);
private:
	char name; // name of Point(auto set A, B, C, D)
	int x  = 0, y = 0; // instance field
	static int count; // static field, ONE of outr class, in global(STATIC) memory
	//static const double SIZE = 10;
};

