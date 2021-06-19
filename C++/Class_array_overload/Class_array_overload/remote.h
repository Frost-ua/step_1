#pragma once
//#include "tv.h"

class tv;

class remote
{
public:
	remote(tv* the_tv);
	void power(bool tv_state);
	void go_channel(size_t channel);
	void set_remote(tv *tv_name);
	void operator ++ ();
	void operator -- ();
	void operator + ();
	void operator - ();
	/*~remote();*/

private:
	tv* the_tv = nullptr;

};

