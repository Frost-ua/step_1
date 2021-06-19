#include <iostream>
#include <string>
#include "remote.h"
#pragma once

using namespace std;

class remote;

class tv {

public:	
	
	tv(bool tv_state, size_t amount_channels, size_t max_volume, size_t current_channel, size_t current_volume);
	tv(bool tv_state);
	tv();
	void set_tv_state(bool tv_state);
	void set_current_channel(size_t current_channel);
	void set_current_volume(size_t current_volume);
	void power(bool tv_state);
	void next_channel();
	void prev_channel();
	void inc_volume();
	void dec_volume();
	void show() const;

private:
	const size_t MAX_VOLUME = 50;
	bool tv_state;
	size_t current_volume;
	size_t current_channel;
	const size_t AMOUNT_CHANNELS = 100;
	//friend class remote;
	friend void remote::go_channel(size_t channel);       // ------------------ ????????????????????????????????
};
