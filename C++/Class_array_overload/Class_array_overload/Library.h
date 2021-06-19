#pragma once
#include"Book.h"
#include<vector>
#include<algorithm>

class Library
{
public:
	Library() = default;
	
	void addBook(const string& author, const string& book_name, const size_t& year);
	Book& searchBook(const string& author, const string& book_name);
	void searchBookByAuthor(const string& author)const;
	void borrowBook(const string& author, const string& book_name);
	void returnBook(const string& author, const string& book_name);
	void sortBook();
	void deleteBook(const string& author, const string& book_name, const size_t& year);
	void editBook(const string& author, const string& book_name);
	void printAllBooks()const;
	void writeLibToFile(bool append)const;
	Library readLibFromFile();
	
private:
	vector<Book> all_books{};
	string file_name = "Library.xml";
};

inline void Library::addBook(const string& author, const string& book_name, const size_t& year)
{
	Book *new_book = new Book(author, book_name, year);
	all_books.push_back(*new_book);
}

inline Book& Library::searchBook(const string& author, const string& book_name)
{
	bool found = false;
	for (size_t i = 0; i < all_books.size(); i++)
	{
		if (all_books[i].getAuthor() == author && all_books[i].getBookName() == book_name)
		{
			found = true;
			return all_books[i];
		}
	}
	if (!found)
	{
		Book* tmp = new Book;
		return *tmp;
	}
}

inline void Library::searchBookByAuthor(const string& author) const
{
	bool book_found = false;
	cout << "All books by " << author << " : \n";
	for (size_t i = 0; i < all_books.size(); i++)
	{
		
		if (all_books[i].getAuthor() == author)
		{
			cout << all_books[i].getBookName() << ", " << all_books[i].getYear() <<  endl;
			book_found = true;
		}
	}
	if (!book_found)
	{
		cout << "No one book by " << author << " found.\n";
	}
}

inline void Library::borrowBook(const string& author, const string& book_name)
{
	if (searchBook(author, book_name).getAvailable())
	{
		cout << book_name << " by " << author << " found. Enjoy reading :)\n";
		searchBook(author, book_name).setAvailable(false);
	}
	else
	{
		cout << book_name << " by " << author << " not found. Visit us later.\n";
	}
}

inline void Library::returnBook(const string& author, const string& book_name)
{
	if (searchBook(author, book_name).getAuthor() == author && searchBook(author, book_name).getBookName() == book_name)
	{
		searchBook(author, book_name).setAvailable(true);
		cout << "Thank you for visiting. You are welcome :)\n";
	}
	else
	{
		cout << book_name << " by " << author << " not found. This isn't our book!.\n";
	}
}

inline void Library::sortBook()
{
	sort(all_books.begin(), all_books.end());
}

inline void Library::deleteBook(const string& author, const string& book_name, const size_t& year)
{
	for (size_t i = 0; i < all_books.size(); i++)
	{
		if (all_books[i].getAuthor() == author && all_books[i].getBookName() == book_name && all_books[i].getYear() == year)
		{
			all_books.erase(all_books.begin() + i);
		}
	}
}

inline void Library::editBook(const string& author, const string& book_name)
{
	Book &result = searchBook(author, book_name);
	if (result.getAuthor() == author && result.getBookName() == book_name)
	{
		string new_author_name, new_book_name;
		size_t new_year = 0;
		cout << "Enter a new author name : ";
		getline(cin, new_author_name);
		cout << "Enter a new book name : ";
		getline(cin, new_book_name);
		cout << "Enter a new book year : ";
		cin >> new_year;
		result.setAuthor(new_author_name);
		result.setBookName(new_book_name);
		result.setYear(new_year);
		cout << "The book has been successfully edited\n";
	}
	else
	{
		cout << book_name << " by " << author << " not found.\n";
	}
}

inline void Library::printAllBooks() const
{
	for (size_t i = 0; i < all_books.size(); i++)
	{
		cout << all_books[i].getAuthor() << "   ----------   " << all_books[i].getBookName() << " , " << all_books[i].getYear() << endl;
	}
}

inline void Library::writeLibToFile(bool append) const
{
	ofstream out;

	if (append)
	{
		out.open(file_name, ios_base::app);
	}
	else
	{
		out.open(file_name);
	}
	if (!out.is_open())
	{
		cerr << "Error open for write(append)\n";
		return;
	}			
	for (size_t i = 0; i < all_books.size(); i++)
	{
		out << all_books[i];
	}
	out.close();
}

inline Library Library::readLibFromFile()
{
	ifstream fin(file_name);
	if (!fin.is_open())
	{
		cerr << "Error open for write(append)\n";
		
	}
	else
	{
		Book tmp;
		string author, book_name, d;
		size_t year = 0;
		bool available = false;
		for (size_t i = 0; i < 13; i++)
		{
			fin >> tmp;
			all_books.push_back(tmp);
		}
	}
	fin.close();
	return *this;
}



