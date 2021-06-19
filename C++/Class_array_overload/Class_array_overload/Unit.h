#pragma once
#include <string>

using namespace std;

class Unit //abstract
{
public:
	Unit(int hp, int dmg, int dodge, const std::string name, int initiative);
	Unit();

	int get_hp() const;
	int get_dmg() const;
	int get_dodge() const;
	std::string get_name() const;
	int get_initiative() const;
	string get_race() const;

	void attack(Unit & other) const;
	bool dodge_attack(Unit& other) const;
	void die(Unit& other) const;
	bool is_unit_die();
	void set_race(string race);
	
protected:
	void set_hp(int hp);
	void set_dmg(int dmg);
	void set_dodge(int dodge);
	void set_name(string name);
	void set_initiative(int initiative);
	
private:
	static const size_t MIN_HP = 1;
	static const size_t MIN_DMG = 1;
	static const size_t MIN_DODGE = 1;
	static const size_t MIN_INITIATIVE = 1;
	int hp;
	int dmg;
	int dodge;
	int initiative;
	string name;
	string race;
};
