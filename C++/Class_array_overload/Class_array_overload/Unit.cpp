#include <iostream>
#include <string>
#include <ctime>
#include "Unit.h"
#include "Team.h"

using namespace std;

Unit::Unit(int hp, int dmg, int dodge, std::string name, int initiative)
{
	set_hp(hp);
	set_dmg(dmg);
	set_dodge(dodge);
	set_name(name);
}

Unit::Unit()
{
	hp = MIN_HP;
	dmg = MIN_DMG;
	dodge = MIN_DODGE;
}

void Unit::set_hp(int hp)
{
	hp > 0 ? this->hp = hp : MIN_HP;
}

void Unit::set_dmg(int dmg)
{
	dmg > 0 ? this->dmg = dmg : MIN_DMG;
}

void Unit::set_dodge(int dodge)
{
	dodge > 0 ? this->dodge = dodge : MIN_DODGE;
}

void Unit::set_name(string name)
{
	this->name = name;
}

void Unit::set_initiative(int initiative)
{
	initiative > 0 ? this->initiative = initiative : MIN_INITIATIVE;
}

void Unit::set_race(string race)
{
	this->race = race;
}

int Unit::get_hp() const
{
	return hp;
}

int Unit::get_dmg() const
{
	return dmg;
}

int Unit::get_dodge() const
{
	return dodge;
}

std::string Unit::get_name() const
{
	return name;
}

int Unit::get_initiative() const
{
	return initiative;
}

string Unit::get_race() const
{
	return race;
}

void Unit::attack(Unit& other) const
{
	cout  << this->get_race() << ":\t" << this->get_name() << " attacks " << other.get_name() << endl;
	if (dodge_attack(other))
	{
		std::cout << "\t" << other.get_name() << " reflects the attack " << std::endl;
	}
	else
	{
		cout << "\t" << other.get_name() << " gets " << this->get_dmg() << " damaged " << endl;
		other.hp -= this->dmg;
		die(other);
	}
}

bool Unit::dodge_attack(Unit& other) const
{
	int chanse = rand() % 100 + 1;
	if (chanse <= other.dodge)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Unit::die(Unit& other) const
{
	if (other.hp <= 0)
		std::cout << "\t" << other.get_name() <<" is dead" << std::endl;
}

bool Unit::is_unit_die()
{
	if (this->hp <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

