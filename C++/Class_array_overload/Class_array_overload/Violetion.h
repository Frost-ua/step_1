#pragma once
#include<string>
#include "Date.h"
using std::string;
using std::cout;
using std::endl;

class Violetion
{
public:
	Violetion(const string &title, const Date &date, const size_t &amount_of_fine);
	Violetion() = default;
	void setTitle(const string &title);
	void setAmountOfFine(const size_t& amount_of_fine);
	string getTitle()const { return title; };
	size_t getAmountOfFine() { return amount_of_fine; };
	void printViolation()const;
private:
	string title = "Description of the offense";
	Date date;
	size_t amount_of_fine = 0;
};

inline Violetion::Violetion(const string& title, const Date& date, const size_t& amount_of_fine)
{
	setTitle(title);
	this->date = date;
	setAmountOfFine(amount_of_fine);
}

inline void Violetion::setTitle(const string& title)
{
	!title.empty() ? this->title = title : "Description of the offense";
}

inline void Violetion::setAmountOfFine(const size_t& amount_of_fine)
{
	amount_of_fine > 0 ? this->amount_of_fine = amount_of_fine : 0;
}

inline void Violetion::printViolation() const
{
	cout << "Date: \t\t\t\t" << date.getDay() << ". " << date.getMonth() << ". " << date.getYear() << endl;
	cout << "The reason: \t\t\t" <<title << endl;
	cout << "The fine: \t\t\t" << amount_of_fine << "$" << endl;
}















