#pragma once
#include<string>
#include<iostream>
#include<ostream>
#include<fstream>
using namespace std;

class Book
{
public:
	
	Book(const string& author, const string& book_name, const size_t& year, bool available = true);
	Book() = default;
	void setAuthor(const string& author);
	void setBookName(const string& book_name);
	void setYear(const size_t& year);
	void setAvailable(bool available);
	string getAuthor()const { return author; };
	string getBookName()const { return book_name; };
	size_t getYear()const { return year; };
	bool getAvailable()const { return available; };
	bool operator < (const Book& other)const;
	Book& operator = (const Book& other);

private:
	string author = "No name";
	string book_name = "No name";
	size_t year = MIN_YEAR;
	bool available = false;
	const size_t MIN_YEAR = 0;
};

ostream& operator << (ostream& out, const Book& book)
{
	out << book.getAuthor() << endl << book.getBookName() << endl << book.getYear() << endl << book.getAvailable() << endl;
	return out;
}
void operator >> (std::istream& in, Book& book)
{
	string author, book_name, d;
	size_t year = 0;
	bool available = false;

	getline(in, author);
	getline(in, book_name);
	in.eof();
	in >> year;
	in >> available;
	getline(in, d);
	book.setAuthor(author);
	book.setBookName(book_name);
	book.setYear(year);
	book.setAvailable(available);
}

inline Book::Book(const string& author, const string& book_name, const size_t& year, bool available)
{
	setAuthor(author);
	setBookName(book_name);
	setYear(year);
	setAvailable(available);
}

inline void Book::setAuthor(const string& author)
{
	!author.empty() ? this->author = author : "No name";
}

inline void Book::setBookName(const string& book_name)
{
	!book_name.empty() ? this->book_name = book_name : "No name";
}

inline void Book::setYear(const size_t& year)
{
	year > 0 ? this->year = year : MIN_YEAR;
}

inline void Book::setAvailable(bool available)
{
	this->available = available;
}

inline bool Book::operator<(const Book& other)const
{
	if (this->author < other.author)
	{
		return true;
	}
	else if (this->author == other.author && this->book_name < other.book_name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline Book& Book::operator=(const Book& other)
{
	this->author = other.author;
	this->book_name = other.book_name;
	this->year = other.year;
	this->available = other.available;
	return *this;
}



