#include <iostream>
#include "room.h"

//--------------------------------Done---------------------

std::string room::quater_to_string[4]{ "North", "South", "West", "East" };

room::room(double width, double length, quarter room_quarter) {
	set_width(width);
	set_lenght(length);
	set_quarter(room_quarter);
}

room::room(double width)
	:room(width, length = 6, NORTH)
{}

/*
room::room()
{
	width = MIN_WIDTH;
	length = MIN_LENGTH;
	room_quarter = NORTH;
}*/

double room::get_width() const { return width; }
double room::get_lenght() const { return length; }
room::quarter room::get_quarter(){ return room_quarter; }

void room::set_width(double width) {
	if (width > 0)
	{
		this->width = width;
	}
	else
	{
		this->width = MIN_WIDTH;
	}
}

void room::set_lenght(double lenght) {
	if (lenght > 0)
	{
		this->length = lenght;
	}
	else
	{
		this->length = MIN_LENGTH;
	}	
}

void room::set_quarter(quarter room_quarter) {
	this->room_quarter = room_quarter;
}

double room::room_square(double width, double length) const{
	return width * length;
}

void room::print_room_info() const
{
	std::cout << "Quarter: ";
	room::show_quater(room_quarter);
	std::cout << "Size:\t";
	std::cout << "W: " << width << " \t";
	std::cout << "L: " << length << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

void room::show_quater(quarter r_quarter)
{
	std::cout << quater_to_string[r_quarter] << "\t\t";
}

void room::set_room(double width, double length, quarter room_quarter)
{
	set_width(width);
	set_lenght(length);
	set_quarter(room_quarter);
}

room &room::operator=(room& other)
{
	this->room_quarter = other.room_quarter;
	this->width = other.width;
	this->length = other.length;

	return *this;
}

room room::operator+(room& other) const
{
	room result(this->width + other.width, this->length + other.length, this->room_quarter);
	return result;
}

room room::operator+(double value) const
{
	room result(this->width + value, this->length + value, this->room_quarter);
	return result;
}

room &room::operator-(int value) const
{
	if (width - value >= MIN_WIDTH && length - value >= MIN_LENGTH)
	{
		room result(width - value, length - value, room_quarter);
		return result;
	}
}

room room::operator*(int value) const
{
	room result(width * value, length * value, room_quarter);
	return result;
}

room &room::operator++()
{
	width++;
	length++;
	return *this;
}

room room::operator++(int)
{
	room tmp(*this);
	++*this;
	return tmp;
}

room& room::operator--()
{
	
	if (width - 1 >= MIN_WIDTH && length - 1 >= MIN_LENGTH)
	{
		width--;
		length--;
	}
	return *this;
	
}

room room::operator--(int)
{
	room tmp(*this);
	if (width - 1 >= MIN_WIDTH && length - 1 >= MIN_LENGTH)
	{
		--* this;
	}
	return tmp;
}

bool room::operator==(room& other) const
{
	return width == other.width && length == other.length && room_quarter == other.room_quarter;
}

bool room::operator!=(room& other) const
{
	return !(*this == other);
}

bool room::operator>(room& other) const
{
	return (room_square(width, length) > room_square(other.width, other.length));
}

bool room::operator<(room& other) const
{
	return !(room_square(width, length) > room_square(other.width, other.length));
}

room &room::operator+=(int value)
{
	width += value;
	length += value;
	return *this;
}

room& room::operator*=(int value)
{
	width *= value;
	length *= value;
	return *this;
}