#include "ZooWorker.h"
#include <ctime>

ZooWorker::ZooWorker(const string& name)
{
	set_zoo_worker_name(name);
}

ZooWorker& ZooWorker::operator[](size_t index)
{
	return this[index];
}

void ZooWorker::Watch(Animal& animal) const
{
	if (!get_already_watching())
	{
		cout << "Zoo worker " << name << " is watching the " << animal.get_kind() << " " << animal.get_name() << " \n";
		animal.random_action(animal);
		const_cast<ZooWorker&>(*this).object_of_observation = animal.get_name();
		const_cast<ZooWorker&>(*this).already_watching = true;
	}
	else
	{
		cout << "Zoo worker " << get_zoo_worker_name() << " is busy!\n";
	}
}

void ZooWorker::FeedAnimal(const Animal& animal) const
{
	if (!get_already_watching())
	{
		cout << this->get_zoo_worker_name() << " is feeding the " << animal.get_kind() << " " << animal.get_name() << "\n\n";
		const_cast <Animal&>(animal).set_is_eating(true);
		const_cast<ZooWorker&>(*this).object_of_observation = animal.get_name();
		const_cast<ZooWorker&>(*this).already_watching = true;
	}
	else if (get_already_watching() && get_object_of_observation() == animal.get_name())
	{
		cout << this->get_zoo_worker_name() << " is feeding the " << animal.get_kind() << " " << animal.get_name() << "\n\n";
	}
	else
	{
		cout << "Zoo worker " << get_zoo_worker_name() << " is busy!\n";
	}
}

bool ZooWorker::get_already_watching() const
{
	return already_watching;
}

void ZooWorker::set_already_watching(bool a)
{
	already_watching = a;
}

void ZooWorker::set_object_of_observation(string& name)
{
	object_of_observation = name;
}

string ZooWorker::get_object_of_observation() const
{
	return object_of_observation;
}

string ZooWorker::get_zoo_worker_name() const
{
	return name;
}

void ZooWorker::set_zoo_worker_name(const string& name)
{
	(!empty(name)) ? this->name = name : "Noname";
}
