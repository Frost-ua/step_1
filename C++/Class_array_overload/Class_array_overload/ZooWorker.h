#pragma once
#include "lib.h"

class ZooWorker : public IWatch
{
public:
	ZooWorker(const string& name);
	ZooWorker() = default;

	ZooWorker& operator [] (size_t index);
	virtual void Watch(Animal& animal) const override;
	void FeedAnimal(const Animal & animal) const;
	bool get_already_watching() const;
	void set_already_watching(bool a);
	void set_object_of_observation(string& name);
	string get_object_of_observation() const;
	string get_zoo_worker_name() const;
	void set_zoo_worker_name(const string& name);

private:
	string name = "Noname";
	bool already_watching = false;
	string object_of_observation;
};






