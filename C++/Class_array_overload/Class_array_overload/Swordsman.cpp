#include "Swordsman.h"
#include <string>

Swordsman::Swordsman(int hp, int dmg, int dodge, std::string name, int initiative)
	:Unit(hp = 15, dmg = 5, dodge = 60, name = "Swordsman", initiative = rand() % 10 + 1)
{
	
}

Swordsman::Swordsman()
{
	set_hp(15);
	set_dmg(5);
	set_dodge(60);
	set_name("Swordsman");
	set_initiative(rand() % 10 + 1);
	
}
