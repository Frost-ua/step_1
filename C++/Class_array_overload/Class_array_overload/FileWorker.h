#pragma once
#include<string>
#include<fstream>
#include <iostream>
using namespace std;

class FileWorker
{
public:
	static void writeTextFile(const string& fname, bool append = false); //append == true - adding to the file, append == false - rewrite the file
	static void printTextFile(const string& fname);
	static void copyFile(const string& from, const string& to);

private:
};

inline void FileWorker::writeTextFile(const string& fname, bool append)
{
	ofstream out; // created a stream object, but will link the file later

	if (append)
	{
		out.open(fname, ios_base::app); // open stream for adding to the end of the file
	}
	else
	{
		out.open(fname); // open stream for rewrite the file
	}
	if (!out.is_open())//   !out//   !out.good()) if the file not opened - error 
	{
		cerr << "Error open for write(append)\n";
		return;
	}
	// 1) read line by line
	string line;
	cout << "Enter lines, stop with Ctrl-z\n";
	while (getline(cin, line))
	{
		out << line << endl;
	}
	out.close(); // not necessarily, because dtor will do it in the end of method. Obj "out" will be destroyed

	//2) read char by char
}

inline void FileWorker::printTextFile(const string& fname)
{
	// 1) line by line
	ifstream fin(fname);
	if (!fin.is_open())
	{
		cerr << "Error open file " << fname << " for read\n";
		return;
	}
	cout << "------------Content of file : " << fname << "----------\n";

	string line;
	while (getline(fin, line))
	{
		cout << line << endl;
	}
	cout << "------------" << fname << "----------\n";

	//2) char by char

	/*char symbol;
	while (fin.get(symbol))   // read each symbol, end check if fin.good()
	{						   						
		cout.put(symbol);
	}
	cout << "------------" << fname << "----------\n";*/
	fin.close();
}

inline void FileWorker::copyFile(const string& from, const string& to)
{
	ifstream fin(from);
	ofstream fout(to);
	if (! fin || !fout)
	{
		cerr << "Couldn't open file(s) for coying\n";
		return;
	}
	char symbol;
	while (fin.get(symbol))
	{
		/*if (islower(symbol))           //Here we can write different filters
		{
			fout << (char)toupper(symbol);
		}
		else
		{
			fout << symbol;
		}*/
		
		fout << symbol;
	}
	fin.close();
	fout.close();

}

