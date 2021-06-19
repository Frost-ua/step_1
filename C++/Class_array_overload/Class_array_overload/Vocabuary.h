#pragma once
#include <iostream>
#include <string>
#include <map>
#include<fstream>

using namespace std;

class Vocabuary
{
public:
	Vocabuary() = default;
	void addWord(const string& original, const string& translate);
	string searchTranslate(const string& original);
	void editWord(const string& original, const string& translate);
	void deleteWord(const string& original);
	void print()const;
	void writeTextToFile(bool append = false)const; //append == true - adding to the file, append == false - rewrite the file
	void printTextFromFile()const;
	
private:
	map <string, string>  vocabuary
	{
		{"Book", "Knyga"},
		{"Apple", "Yabloko"},
		{"Pen", "Ruchka"},
		{"Phone", "Telephone"},
		{"Table", "Stil"}
	};
	string file_name = "Vocabuary.xml";
};


inline void Vocabuary::addWord(const string& original, const string& translate)
{
	vocabuary.insert({ original, translate });

}

inline string Vocabuary::searchTranslate(const string& original)
{
	if (vocabuary.find(original) != vocabuary.end())
	{
		cout << vocabuary[original] << endl << endl;
	}
	return vocabuary[original];
}

inline void Vocabuary::editWord(const string& original, const string& translate)
{
	if (vocabuary.find(original) != vocabuary.end())
	{
		vocabuary[original] = translate;
	}
}

inline void Vocabuary::deleteWord(const string& original)
{
	if (vocabuary.find(original) != vocabuary.end())
	{
		vocabuary.erase(original);
	}
}

inline void Vocabuary::print() const
{
	for (auto& e : vocabuary)
	{
		cout << e.first << "\t--- \t" << e.second << endl;
	
	}
	cout << endl;
}

inline void Vocabuary::writeTextToFile(bool append)const
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
	}																	// read line by line
	for (auto& e : vocabuary)
	{
		out << e.first << "\t   ---   \t" << e.second << endl;
	}
	out.close(); 
}

inline void Vocabuary::printTextFromFile()const
{
	ifstream fin(file_name);
																						// char by char
	char symbol;
	while (fin.get(symbol))												 // read each symbol, end check if fin.good()
	{
		cout.put(symbol);
	}
	fin.close();
}


















// {
// 	//pair<int, string> p = make_pair(1, "one");
// 	map<int, string/*, greater<int>*/ > people
// 	{
// 		{100, "Vasil"},
// 		make_pair(55, "Mykola"),
// 		pair<int, string>(77, "Olena")
// 	};
// 	people.insert({ 35, "Maryna" });
// 	print(people, "People");
// 
// 	people[55] = "Mykola Petrenko"; // 
// 	people[1] = "Vadym";
// 	print(people, "\nPeople");
// 
// 	int id;
// 	cout << "\nEnter  id : ";
// 	cin >> id;
// 	string  name;
// 	cout << "Enter  name : ";
// 	cin >> name;
// 
// 	if (people.find(id) != people.end())
// 	{
// 		people[id] = name;
// 		cout << "Successfully edited\n";
// 	}
// 	else
// 	{
// 		cout << "This id not found!\n";
// 	}
// 	try {
// 		people.at(770) = "Olena O.";
// 		print(people, "\nPeople");
// 	}
// 	catch (exception& ex)
// 	{
// 		cout << "Error(id not  found) : " << ex.what() << endl;
// 	}
// 
// 
// }