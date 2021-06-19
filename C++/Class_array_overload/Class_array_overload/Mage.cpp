#include "Mage.h"
#include <string>

Mage::Mage(int hp, int dmg, int dodge, std::string name, int initiative)
	:Unit(hp = 8, dmg = 10, dodge = 30, name = "Mage", initiative = rand() % 10 + 1)
{
}

Mage::Mage()
{
	set_hp(8);
	set_dmg(10);
	set_dodge(30);
	set_name("Mage");
	set_initiative(rand() % 10 + 1);
}
