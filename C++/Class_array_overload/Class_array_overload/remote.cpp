#include "tv.h"
#include "remote.h"



remote::remote(tv* the_tv)
{
	this->the_tv = the_tv;
}

void remote::power(bool tv_state)
{
	the_tv->power(tv_state);
}

void remote::go_channel(size_t channel)
{
	the_tv->current_channel = channel;                    // use friend class
}

void remote::set_remote(tv *tv_name)
{
	the_tv = tv_name;
}

void remote::operator++()
{
	the_tv->next_channel();
}

void remote::operator--()
{
	the_tv->prev_channel();
}

void remote::operator+()
{
	the_tv->inc_volume();
}

void remote::operator-()
{
	the_tv->dec_volume();
}

/*
remote::~remote()
{

}
*/
