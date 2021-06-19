#pragma once
#include<ctime>
#include <ctime>

class Bullet
{
public:
	Bullet();
	static size_t getBulletId();
	virtual void shoot() const;

private:
	static size_t start_id;
	size_t	bullet_id = 0;
	size_t probability_of_hit = 70;
};

size_t Bullet::start_id = Bullet::getBulletId();

inline Bullet::Bullet()
{
	this->bullet_id = start_id;
	++start_id;
}
inline size_t Bullet::getBulletId()
{
	srand(unsigned int(time(NULL)));
	size_t id = rand() % 10 + 1;
	return id;
}

inline void Bullet::shoot() const
{
	size_t chanse = rand() % 100 + 1;
	if (chanse <= probability_of_hit)
	{
		std::cout << "The gun fired a bullet " << bullet_id << " and hit.\n";
	}
	else
	{
		std::cout << "The gun fired a bullet " << bullet_id << " and missed.\n";
	}
}
