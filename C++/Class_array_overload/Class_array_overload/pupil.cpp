#include <iostream>
#include <string>
#include "pupil.h"

using namespace std;


pupil::pupil(const string& pupil_name, const string& pupil_surname, const string& city, size_t amount_marks = 10)
{
	set_pupil_name(pupil_name);
	set_pupil_surname(pupil_surname);
	set_city(city);
	set_amount_marks(amount_marks);
	marks = new size_t[amount_marks]{};
}

pupil::pupil(const string& pupil_name, const string& pupil_surname, const string& city, initializer_list<int> list)    // new!
{
	set_pupil_name(pupil_name);
	set_pupil_surname(pupil_surname);
	set_city(city);
	setMarks(list);                                                // new!
}

pupil::pupil()
{
	pupil_name = "Noname";
	pupil_surname = "Noname";
	city = "Noname";
	marks = nullptr;
	amount_marks = 10;
}

pupil& pupil::operator=(const pupil& other)
{

	this->pupil_name = other.pupil_name;
	this->pupil_surname = other.pupil_surname;
	this->city = other.city;
	this->amount_marks = other.amount_marks;

	if (marks != nullptr)
		delete[] marks;
	marks = new size_t[amount_marks];
	for (size_t i = 0; i < amount_marks; i++)
	{
		marks[i] = other.marks[i];
	}

	return *this;
}

pupil::pupil(const pupil& other)
{
	this->pupil_name = other.pupil_name;
	this->pupil_surname = other.pupil_surname;
	this->city = other.city;
	this->amount_marks = other.amount_marks;

	if (marks != nullptr)
		delete[] marks;
	marks = new size_t[amount_marks];                             

	for (int i = 0; i < amount_marks; i++)                         
	{
		marks[i] = other.marks[i];
	}
}

void pupil::set_mark(size_t lesson, size_t mark)
{
	if (mark >= MIN_MARK && mark <= MAX_MARK)
	{
		if (lesson > 0 && lesson <= amount_marks)
		{
			marks[lesson - 1] = mark;
		}
		else
		{
			cout << "\nLesson number doesn't exist! Choose lesson from 1 to " << amount_marks << endl << endl;
			system("Pause");
		}
	}
	else
	{
		cout << "\nYou entered incorrect mark! Enter mark from " << MIN_MARK << " to " << MAX_MARK << endl << endl;
		system("Pause");
	}
}

void pupil::setMarks(initializer_list<int> list)                                            // new!
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list.begin()[i] < MIN_MARK || list.begin()[i] > MAX_MARK)
		{
			const_cast<int&>(list.begin()[i]) = 0;
		}
	}
	marks_list = list;
	amount_marks = list.size();
	marks = new size_t[amount_marks];
	for (size_t i = 0; i < list.size(); i++)
	{
		marks[i] = list.begin()[i];
	}


	
}

void pupil::set_pupil_name(string name)
{
	this->pupil_name = name;
}

void pupil::set_pupil_surname(string surname)
{
	this->pupil_surname = surname;
}

void pupil::set_city(string city)
{
	this->city = city;
}

void pupil::set_amount_marks(size_t amount_marks)
{
	if (amount_marks > 0)
	{
		this->amount_marks = amount_marks;
	}
	else
	{
		this->amount_marks = 10;
	}
}


string pupil::get_name() const
{
	return pupil_name;
}

string pupil::get_surname() const
{
	return pupil_surname;
}

string pupil::get_city() const
{
	return city;
}

size_t pupil::get_amount_marks() const
{
	return amount_marks;
}

void pupil::print_pupil_info() const
{
	cout << "\n" << get_name() << " " << get_surname() << " --- " << get_city() << "\nMarks: ";
	
	if (marks == nullptr)
	{
		for (size_t i = 0; i < marks_list.size(); i++)                                   // new!
		{
			cout << marks_list.begin()[i] << "\t";
		}
	}
	else
	{
		for (size_t i = 0; i < get_amount_marks(); i++)
		{
			cout << marks[i] << "\t";
		}
	}

	

}

pupil::~pupil()
{
	delete[] this->marks;
}
