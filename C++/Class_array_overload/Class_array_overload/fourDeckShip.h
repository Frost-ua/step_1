#pragma once
#include<vector>
#include"Ship_.h"
#include"Deck.h"

class fourDeckShip : public Ship_
{
public:
	fourDeckShip(const string& name = "Four-deck ship", size_t ship_size = 4)
		:Ship_(name, ship_size)
	{};
private:
	string name;
};


