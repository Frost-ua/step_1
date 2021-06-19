#include "Archer.h"
#include <string>
using namespace std;

Archer::Archer(int hp, int dmg, int dodge, std::string name, int initiative)
	:Unit(hp = 12, dmg = 4, dodge = 40, name = "Archer", initiative = rand() % 10 + 1)
{
	
}

Archer::Archer()
{
	set_hp(12);
	set_dmg(4);
	set_dodge(40);
	set_name("Archer");
	set_initiative(rand() % 10 + 1);
}
