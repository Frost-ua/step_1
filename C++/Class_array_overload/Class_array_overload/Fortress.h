
#pragma once
#include "Tower.h"
#include "Catapult.h"


class Fortress : public Tower, public Catapult
{
public:
	Fortress(size_t ammunition_amount_tower, size_t ammunition_amount_catapult, const string& ammunition_name_tower = "arrow", const string& ammunition_name_catapult = "stone", size_t wall_thickness = 5, size_t gate_condition = 80)
		:Tower::Shooter(ammunition_amount_tower, ammunition_name_tower), Tower(ammunition_amount_tower, ammunition_name_tower), Catapult(ammunition_amount_catapult, ammunition_name_catapult)
	{
		setWallThickness(wall_thickness);
		setGateCondition(gate_condition);
	}
	void setWallThickness(size_t wall_thickness);
	void setGateCondition(size_t gate_condition);
private:
	size_t wall_thickness;
	size_t gate_condition;
};

inline void Fortress::setWallThickness(size_t wall_thickness)
{
	wall_thickness > 0 ? this->wall_thickness = wall_thickness : this->wall_thickness = 5;
}

inline void Fortress::setGateCondition(size_t gate_condition)
{
	gate_condition > 0 ? this->gate_condition = gate_condition : this->gate_condition = 10;
}