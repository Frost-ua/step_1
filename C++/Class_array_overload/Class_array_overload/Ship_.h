#pragma once
#include<vector>
#include<iostream>
#include"Deck.h"


class Ship_
{
public:
	enum shipStatus { DEAD, LIVE };
	enum deckNumber { FIRST, SECOND, THIRD, FOURTH };

	Ship_(const string& name, size_t size);
	
	// getters
	bool getShipStatus()const { return ship_status; };
	string getName()const { return name; };
	std::vector<Deck>& getShip() { return ship; };
	
	// setters
	void setShipStatus(shipStatus status);
	
	// methods
	void die();
	void printShipInfo()const;
	
private:
	bool ship_status = shipStatus::LIVE;
	std::vector<Deck> ship{};
	string name;
};

//==================================================================

inline Ship_::Ship_(const string& name, size_t size)    //ctor
{
	this->name = name;
	for (size_t i = 0; i < size; i++)
	{
		Deck* tmp = new Deck();
		ship.push_back(*tmp);
	}
}

inline void Ship_::die()
{
	size_t hp = ship.size();
	for (size_t i = 0; i < ship.size(); i++)
	{
		if (ship[i].getDeckStatus())
		{
			--hp;
		}
	}
	if (hp == 0)
	{
		ship_status = shipStatus::DEAD;
	}
}

inline void Ship_::setShipStatus(shipStatus status)
{
	this->ship_status = status;
}

inline void Ship_::printShipInfo() const
{
	if (ship_status == LIVE)
	{
		std::cout << name << " is alive.\n";
		for (size_t i = 0; i < ship.size(); i++)
		{
			cout << "X:" << ship[i].getX() << "\t" << "Y:" << ship[i].getY() << "\t" << boolalpha << ship[i].getDeckStatus() << endl;
		}
	}
	else
	{
		std::cout << "The ship is dead.\n";
	}
}


