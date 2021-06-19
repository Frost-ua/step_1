#pragma once
#include "lib.h"

class VideoCamera : public IWatch
{
public:
	VideoCamera();

	VideoCamera& operator [] (size_t index);
	virtual void Watch(Animal& animal) const override;
	void set_id(size_t id);
	string get_object_of_observation() const;
	size_t get_id() const;
	bool get_already_watching() const;
	void set_already_watching(bool a);

private:
	size_t id = 0;
	bool already_watching = false;
	string object_of_observation;
};



