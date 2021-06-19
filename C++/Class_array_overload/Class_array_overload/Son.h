#pragma once
#include "Daddy.h"

class Son : public Daddy
{
public:
	Son(const string & name, size_t age, size_t hours_for_walking);
	Son() = default;
	virtual size_t get_age() const;
	virtual void Sleep() const override;
	virtual void Walk() const override;
	virtual void Play() const;
	void show_hours_for_walking() const;
	~Son();
private:
	const size_t hours_for_walking = 2;
	size_t age = 10;
};

inline Son::Son(const string& name, size_t age, size_t hours_for_walking)
	:Daddy(name, age), hours_for_walking(hours_for_walking)
{
}

inline size_t Son::get_age() const
{
	return age;
}

inline void Son::Sleep() const
{
	cout << typeid(*this).name() + 6 << " " << this->get_name() << " was sleeping at 10 a.m.\n";
}

inline void Son::Walk() const
{
	cout << typeid(*this).name() + 6 << " " << this->get_name() << " was walking at 1 p.m.\n";
}

inline void Son::Play() const
{
	cout << typeid(*this).name() + 6 << " " << this->get_name() << " is playing now\n";
}

inline void Son::show_hours_for_walking() const                   // use const_cast for changing "hours_for_walking" 
{
	cout << this->get_name() << " needs " << hours_for_walking << " hours_for_walking\n";
	cout << "After const_cast_______________\n";
	cout << this->get_name() << " needs " << const_cast<size_t&>(hours_for_walking) + hours_for_walking << " hours_for_walking\n";
}

inline Son::~Son()
{
}

inline void PrintFamily_dynamic_cast(Grandpa* family[], size_t SIZE)          // use dynanic_cast
{
	Daddy* tmp_ptr_daddy = nullptr;
	Son* tmp_ptr_son = nullptr;

	for (size_t i = 0; i < SIZE; i++)
	{
		family[i]->Sleep();

		tmp_ptr_daddy = dynamic_cast<Daddy*>(family[i]);
		if (tmp_ptr_daddy != nullptr)
		{
			tmp_ptr_daddy->Walk();
		}

		tmp_ptr_son = dynamic_cast<Son*>(family[i]);
		if (tmp_ptr_son != nullptr)
		{
			tmp_ptr_son->Play();
		}
		cout << "------------------------------------------\n";
	}
}

inline void PrintFamily_static_cast(Grandpa* family[], size_t SIZE)            // use static_cast
{
	Daddy* tmp_ptr_daddy = nullptr;
	Son* tmp_ptr_son = nullptr;

	for (size_t i = 0; i < SIZE; i++)
	{
		family[i]->Sleep();
		
		if (typeid(*family[i]) == typeid(Daddy))
		{
			tmp_ptr_daddy = static_cast<Daddy*>(family[i]);
			tmp_ptr_daddy->Walk();
		}

		if (typeid(*family[i]) == typeid(Son))
		{
			tmp_ptr_son = static_cast<Son*>(family[i]);
			tmp_ptr_son->Walk();
			tmp_ptr_son->Play();
			
		}
		cout << "------------------------------------------\n";
	}
}