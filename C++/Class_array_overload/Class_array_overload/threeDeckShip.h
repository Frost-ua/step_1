#pragma once
#include<vector>
#include"Ship_.h"
#include"Deck.h"

class threeDeckShip : public Ship_
{
public:
	threeDeckShip(const string& name = "Three-deck ship", size_t ship_size = 3)
		:Ship_(name, ship_size)
	{};
private:
	string name;
};




