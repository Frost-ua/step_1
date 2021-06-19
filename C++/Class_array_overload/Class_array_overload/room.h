#pragma once
#include <iostream>
//--------------------------------Done---------------------
class room
{
public:
	enum quarter {
		NORTH, SOUTH, WEST, EAST
	};

	static std::string quater_to_string[4];// { "North", "South", "West", "East" };
	static void show_quater(quarter r_quarter);

	room(double width, double length, quarter room_quarter);
	room(double width);
	room() = default;
	double get_width() const;
	double get_lenght() const;
	quarter get_quarter();
	void set_width(double width);
	void set_lenght(double lenght);
	void set_quarter(quarter room_quarter);
	double room_square(double width, double length) const;
	void print_room_info() const;
	void set_room(double width, double length, quarter room_quarter);
	room &operator = (room& other);
	room operator + (room& other) const;
	room operator + (double value) const;
	room &operator - (int value) const;
	room operator * (int value) const;
	room &operator ++ ();
	room operator ++ (int);
	room &operator -- ();
	room operator -- (int);
	bool operator == (room& other) const;
	bool operator != (room& other) const;
	bool operator > (room& other) const;
	bool operator < (room& other) const;
	room &operator += (int value);
	room &operator *= (int value);

private:
	static const int MIN_WIDTH = 3, MIN_LENGTH = 4;
	double width = MIN_WIDTH;
	double length = MIN_LENGTH;
	quarter room_quarter = NORTH;
	
};

