#pragma once
#include <iostream>

class Deck
{
public:
	enum deckStatus {DEAD, LIVE};
	Deck(size_t x, size_t y, bool deck_status = deckStatus::LIVE);
	Deck() = default;
	// getters
	size_t getX()const { return x; };
	size_t getY()const { return y; };
	bool getDeckStatus()const { return deck_status; };
	
	// setters
	void setX(size_t x);
	void setY(size_t y);
	void setDeckStatus(bool is_unhurt);
	
	// methods
	void deckDie();
private:
	size_t x = 0, y = 0;
	bool deck_status = deckStatus::LIVE;
};

inline Deck::Deck(size_t x, size_t y, bool deck_status)
{
	setX(x);
	setY(y);
	setDeckStatus(deck_status);
}

inline void Deck::setX(size_t x)
{
	x > 0 || x < 9 ? this->x = x : x = 0;
}

inline void Deck::setY(size_t y)
{
	y > 0 || y < 9 ? this->y = y : y = 0;
}

inline void Deck::setDeckStatus(bool deck_status)
{
	this->deck_status = deck_status;
}

inline void Deck::deckDie()
{
	std::cout << "The deck is broken\n";
	this->deck_status = deckStatus::DEAD;
}
