#pragma once
#include <string>
#include "IEat.h"
#include "ISleep.h"
#include "IWalk.h"

class Animal : public IWalk, public IEat, public ISleep
{
public:
	Animal(const std::string& name);
	Animal() = default;

	Animal& operator [] (size_t index);
	std::string get_name() const;
	std::string get_kind() const;
	void set_name(const std::string& name);
	void set_kind(const std::string& kind);
	void set_is_eating(bool a);
	bool get_is_eating() const;
	void random_action(const Animal& animal) const;
	virtual void Walk() const override;
	virtual void Eat() const override;
	virtual void Sleep() const override;
	
private:
	std::string name = "Noname";
	std::string kind = "Noname";
	bool is_eating = false;
};



