#include "Unit.h"

class Mage : public Unit
{
public:
	Mage(int hp, int dmg, int dodge, std::string name, int initiative);
	Mage();
};
