#pragma once
#include "Quest_list.h"
#include <ctime>
using namespace std;
class Game_word
{
public:
	Game_word();
	void run();

private:
	static const char filler = '#';
	Quest_list list;
	string user_word;
	string answer;
};

inline Game_word::Game_word()
{
	Quest_list list;
}

inline void Game_word::run()
{
	srand(unsigned int(time(NULL)));
	size_t choice = rand() % list.getSizeList();
	std::cout << list[choice].getQuastion();
	cout << "\n\n";
	string mask = list[choice].getAnswer();
	
	for (size_t i = 0; i < list[choice].getAnswer().size(); i++)
	{
		mask.replace(i, 1, "*");
	}
	cout << mask;
	bool is_gaming = true;
	while (is_gaming)
	{
		cout << "\n";
		//std::cout << list[choice].getAnswer();                     // print answer
		cout << "\n\n\n";
		cout << "Enter the letter: ";
		cout << "\n";
		string letter;
		cout << "\n";
		cin >> letter;
		bool is_letter = false;
		for (size_t i = 0; i < list[choice].getAnswer().size(); i++)
		{
			if (letter[0] == list[choice].getAnswer()[i] || toupper(letter[0]) == list[choice].getAnswer()[i])
			{
				mask.replace(i, 1, letter);
				is_letter = true;
			}
		}
		if (is_letter)
		{
			system("cls");
			std::cout << list[choice].getQuastion();
			cout << "\n\n" << mask;
		}
		else
		{
			cout << "There is no such letter in the word! You lose!\n\n";
			is_gaming = false;
			system("Pause");
		}
		size_t pos = mask.find("*");
		if (pos == string::npos)
		{
			cout << "\n\nYou guessed the word. You won!\n\n";
			is_gaming = false;
		}
	}
}
