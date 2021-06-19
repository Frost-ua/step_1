#include <iostream>
#include <string>
using namespace std;
#pragma once
//------------------------------------------------  Done -----------------------
class water
{
public:
	enum typeWater {

		LAKE, CHANNEL, BASIN, RESERVOIR, SWAMP
	};

	static int count;
	static std::string quater_to_string[5];// { "Lake", "Channel", "Basin", "Reservoir", "Swamp" };
	
	water(string name, double width, double length, double maxDepth, typeWater type);
	water(string name, double width, double length);
	water();

	string get_name() const;
	double get_width() const;
	double get_length() const;
	double get_maxDepth() const;
	typeWater get_type_water() const;

	void set_name(string name);
	void set_width(double width);
	void set_length(double lendth);
	void set_maxDepth(double maxDepth);
	void set_type_water(typeWater type);

	void show_water_type() const;
	void print_info() const;
	double water_volume() const;
	double water_squere() const;

	static bool compare_type_water(const water &water_1, const water& water_2);
	static int compare_water_squere(const water& water_1, const water& water_2);
	void add_water_to_group() const;
	static water Search_bigest_water(typeWater search_type);
	
private:
	static const size_t MIN_WIDTH = 3;
	static const size_t MIN_LENGTH = 4;
	static const size_t MIN_MAX_DEPTH = 1;
	double width;
	double length;
	double maxDepth;
	string name;
	typeWater type;
	size_t size = 0;
};

class WrongLengthException
{
public:
	WrongLengthException() = default;
	string get_error() const { return error; }
private:
	string error = "\nThe length entered is less than the minimum allowable\n\n";
};

class WrongDepthException
{
public:
	WrongDepthException() = default;
	string get_error() const { return error; }
private:
	string error = "\nThe depth entered is less than the minimum allowable\n\n";
};

class WrongWidthException
{
public:
	WrongWidthException() = default;
	string get_error() const { return error; }
private:
	string error = "\nThe width entered is less than the minimum allowable\n\n";
};

class WrongTypeException
{
public:
	WrongTypeException() = default;
	string get_error() const { return error; }
private:
	string error = "\nThe type of water entered doesn't exist\n\n";
};
