#pragma once
#include "Grandpa.h"

class Daddy : public Grandpa
{
public:
	Daddy(const string& name, size_t age);
	Daddy() = default;
	virtual size_t get_age() const;
	virtual void Walk() const;
	virtual void Sleep() const override;
	~Daddy();
private:
	size_t age = 35;

};

inline Daddy::Daddy(const string& name, size_t age)
	:Grandpa(name, age)
{
}

inline size_t Daddy::get_age() const
{
	return age;
}

inline void Daddy::Walk() const
{
	cout << typeid(*this).name() + 6 << " " << this->get_name() << " is walking now\n";
}

inline void Daddy::Sleep() const
{
	cout << typeid(*this).name() + 6 << " " << this->get_name() << " was sleeping at 9 a.m.\n";
}

inline Daddy::~Daddy()
{
}

