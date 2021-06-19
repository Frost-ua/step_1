#pragma once
#include<vector>
#include"Ship_.h"



class Fleet
{
public:
	Fleet();
	void createFleet();
	std::vector<Ship_>& getFleet() { return fleet; };
	size_t getCountSdShip()const { return count_sd_ship; };
	size_t getCountDdShip()const { return count_dd_ship; };
	size_t getCountThdShip()const { return count_thd_ship; };
	size_t getCountFdShip()const { return count_fd_ship; };

private:
	size_t count_sd_ship = 4;
	size_t count_dd_ship = 3;
	size_t count_thd_ship = 2;
	size_t count_fd_ship = 1;
	std::vector<Ship_> fleet{};
};

inline Fleet::Fleet()
{
	createFleet();
}

inline void Fleet::createFleet()
{
	for (size_t i = 0; i < count_fd_ship; i++)
	{
		Ship_* four_deck_ship = new fourDeckShip;
		fleet.push_back(*four_deck_ship);
	}
	for (size_t i = 0; i < count_thd_ship; i++)
	{
		Ship_* three_deck_ship = new threeDeckShip;
		fleet.push_back(*three_deck_ship);
	}
	for (size_t i = 0; i < count_dd_ship; i++)
	{
		Ship_* doudle_deck_ship = new doubleDeckShip;
		fleet.push_back(*doudle_deck_ship);
	}
	for (size_t i = 0; i < count_sd_ship; i++)
	{
		Ship_* single_deck_ship = new singleDeckShip;
		fleet.push_back(*single_deck_ship);
	}
}



