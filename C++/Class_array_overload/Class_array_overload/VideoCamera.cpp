#include "VideoCamera.h"

VideoCamera::VideoCamera()
{}

VideoCamera& VideoCamera::operator[](size_t index)
{
	return this[index];
}

void VideoCamera::Watch(Animal& animal) const
{
	if (!get_already_watching())
	{
		cout << "Video camera id " << get_id() << " is watching the " << animal.get_kind() << " " << animal.get_name() << " \n";
		animal.random_action(animal);
		const_cast<VideoCamera&>(*this).object_of_observation = animal.get_name();
		const_cast<VideoCamera&>(*this).already_watching = true;
	}
	else
	{
		cout << "Video camera id " << get_id() << " is busy!\n";
	}
}

void VideoCamera::set_id(size_t id)
{
	this->id = id;
}

string VideoCamera::get_object_of_observation() const
{
	return object_of_observation;
}

size_t VideoCamera::get_id() const
{
	return id;
}

bool VideoCamera::get_already_watching() const
{
	return already_watching;
}

void VideoCamera::set_already_watching(bool a)
{
	already_watching = a;
}
