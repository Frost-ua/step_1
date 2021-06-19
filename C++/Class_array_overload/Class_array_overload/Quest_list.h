#pragma once
#include "Quest.h"



class Quest_list
{
public:
	Quest_list();
	const Quest& getQuest(int index);
	Quest& operator [] (const size_t& index);
	size_t getSizeList()const;
	~Quest_list();
private:
	size_t list_size = 5;
	Quest* list;
};

inline Quest_list::Quest_list()
{
	list = new Quest[list_size];
	list[0].setQuest("Author of the C++ programming language.", "STROUSTRUP");
	list[1].setQuest("The world's first high-level programming language.", "PLANKALKUL");
	list[2].setQuest("A continuous sequential chain of blocks containing information.", "BLOCKCHAIN");
	list[3].setQuest("Popular Linux distribution.", "DEBIAN");
	list[4].setQuest("Popular search engine.", "DUCKDUCKGO");
	
}

inline const Quest& Quest_list::getQuest(int index)
{
	return list[index];
}

inline Quest& Quest_list::operator[](const size_t& index)
{
	if (index < list_size)
		return list[index];
}

inline size_t Quest_list::getSizeList() const
{
	return list_size;
}

inline Quest_list::~Quest_list()
{
	if (list != nullptr)
	{
		delete[] list;
	}
}
