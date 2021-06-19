#pragma once
#include<stack>
#include "Bullet.h"
using namespace std;

class Magazine
{
public:
	Magazine(const size_t & capacity);
	void setMagazine();
	const size_t getAmountBullets() const;
	void putBullet();
	Bullet giveBullet();
private:
	size_t capacity;
	stack<Bullet> magazine;
};

inline Magazine::Magazine(const size_t& capacity = 30)
{
	this->capacity = capacity;
	setMagazine();
}

inline void Magazine::setMagazine()
{
	for (size_t i = 0; i < capacity; i++)
	{
		putBullet();
	}
}

inline const size_t Magazine::getAmountBullets() const
{
	return magazine.size();
}

inline void Magazine::putBullet()
{
	if (magazine.size() <= capacity)
	{
		Bullet ex;
		magazine.push(ex);
	}
	else
	{
		cout << "The magazine is full!\n\n";
	}
}

inline Bullet Magazine::giveBullet()
{
	if (!magazine.empty())
	{
		Bullet tmp = magazine.top();
		magazine.pop();
		return tmp;
	}
	else
	{
		throw out_of_range("The magazine is empty!");
	}
}


