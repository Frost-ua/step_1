#pragma once

class point
{
public:
	point(int x, int y);
	point(int x = 0);
	//point() = default;  // default ctor
	static int get_count_points(); // static method doesn't receive THIS
	void print() const;
	static double distance(const point& point_1, const point& point_2);
	static int comparison_two_points(const point& point_0, const point& point_1, const point& point_2);
	char get_name() const { return point_name; }
	void put_point_on_water();
	static void init_water();
	static void print_water();

private:
	char point_name;     // auto set of points A B C D
	int x = 0, y = 0;  // instance field
	static int count; // static field, one of whole class
	static const char DEFAULT_SYMBOL = '.';
	static const int SIZE = 20;
	static char water[SIZE][SIZE];
};

