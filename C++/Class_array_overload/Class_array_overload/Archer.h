#include "Unit.h"

class Archer : public Unit
{
public:
	Archer(int hp, int dmg, int dodge, std::string name, int initiative);
	Archer();

};
