#include "tv.h"
#include "remote.h"
	//	 Constructor with 4 parameters
tv::tv(bool tv_state, size_t amount_channels, size_t max_volume, size_t current_channel = 1, size_t current_volume = 10)
	:AMOUNT_CHANNELS(amount_channels == 0 ? 100 : amount_channels), MAX_VOLUME(max_volume == 0 ? 50 : max_volume)
	{
		set_tv_state(tv_state);
		set_current_channel(current_channel);
		set_current_volume(current_volume);
	}

																													// chain Constructor with 1 parameter
	tv::tv(bool tv_state)
		: tv(tv_state, 100, 50)
	{}

	tv::tv()																											  // default constructor
	{
		tv_state = false;
		current_channel = 1;
		current_volume = 10;
	}

	void tv::set_tv_state(bool tv_state) {

		this->tv_state = tv_state;
	}

	void tv::set_current_channel(size_t current_channel) {

		if (current_channel <= AMOUNT_CHANNELS && current_channel > 0)
		{
			this->current_channel = current_channel;
		}
	}

	void tv::set_current_volume(size_t current_volume) {

		if (current_volume <= MAX_VOLUME && current_volume >= 0)
		{
			this->current_volume = current_volume;
		}
	}

	void tv::power(bool tv_state) {

		this->tv_state = tv_state;

		if (tv_state)
		{
			cout << "Hello, welcome to TV!\n" << endl;
		}
		else if (!tv_state)
		{
			cout << "Bay, thanks for using!\n" << endl;
		}

	}

	void tv::next_channel() {

		if (tv_state)
		{
			current_channel++;

			if (current_channel == AMOUNT_CHANNELS + 1)
			{
				current_channel = 1;
			}

			cout << "Current channel - " << current_channel << endl;
		}
		else if (!tv_state)
		{
			cout << "You must turn on TV, before changing TV channel!\n" << endl;
		}

	}

	void tv::prev_channel() {

		if (tv_state)
		{
			current_channel--;

			if (current_channel == 0)
			{
				current_channel = AMOUNT_CHANNELS;
			}

			cout << "Current channel - " << current_channel << endl;
		}
		else if (!tv_state)
		{
			cout << "You must turn on TV, before changing TV channel!\n" << endl;
		}
	}

	void tv::inc_volume() {

		if (tv_state && current_volume < MAX_VOLUME)
		{
			current_volume++;
		}

		cout << "Current volume - " << current_volume << endl;

		if (current_volume == MAX_VOLUME)
		{
			cout << "Max volume " << MAX_VOLUME << "\n" << endl;
		}
		if (!tv_state)
		{
			cout << "You must turn on TV, before changing TV channel!\n" << endl;
		}
	}

	void tv::dec_volume() {

		if (tv_state && current_volume > 0)
		{
			current_volume--;
		}

		cout << "Current volume - " << current_volume << endl;

		if (current_volume == 0)
		{
			cout << "Min volume 0\n" << endl;
		}
		if (!tv_state)
		{
			cout << "You must turn on TV, before changing TV channel!\n" << endl;
		}
	}

	void tv::show() const {

		if (tv_state)
		{
			cout << "Current volume - " << current_volume << "\nCurrent channel - " << current_channel << "\n" << endl;
		}
		else if (!tv_state)
		{
			cout << "Amount of channels - " << AMOUNT_CHANNELS << "\nMax volume - " << MAX_VOLUME << "\n" << endl;
		}
	}

