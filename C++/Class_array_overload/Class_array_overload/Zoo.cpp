#include "Zoo.h"

Zoo::Zoo()
{
	animals = new Animal[amount_animals]{};
	cctv_cameras = new VideoCamera[amount_cctv_cameras]{};
	workers = new ZooWorker[amount_workers]{};
}

size_t Zoo::get_amount_animals() const
{
	return amount_animals;
}

size_t Zoo::get_amount_workers() const
{
	return amount_workers;
}

size_t Zoo::get_amount_cctv_cameras() const
{
	return amount_cctv_cameras;
}

Animal& Zoo::check_kind_of_animal(const string& kind_of_animal, const string& name) {

	if (kind_of_animal == "Bear" || kind_of_animal == "bear")
	{
		Bear* anml = new Bear(name);
		anml->set_kind("Bear");
		return *anml;					                                
	}
	else if (kind_of_animal == "Parrot" || kind_of_animal == "parrot")
	{
		Parrot* anml = new Parrot(name);
		anml->set_kind("Parrot");
		return *anml;
	}
	else if (kind_of_animal == "Crocodile" || kind_of_animal == "crocodile")
	{
		Crocodile* anml = new Crocodile(name);
		anml->set_kind("Crocodile");
		return *anml;
	}
	else
	{
		throw std::string("The kind of animal entered doesn't exist!\n\n");
	}
}

void Zoo::add_animal(const string& kind_of_animal, const string& name)
{
	if (amount_animals == 0)
	{
		try
		{
			check_kind_of_animal(kind_of_animal, name);
			amount_animals++;
			animals = new Animal[amount_animals]{};
			animals[amount_animals - 1] = check_kind_of_animal(kind_of_animal, name);
			cout << "The animal was added successfully.\n\n";
		}
		catch (const string& ex)
		{
			cout << ex;
		}
	}
	else if (amount_animals > 0)
	{
		try
		{
			check_kind_of_animal(kind_of_animal, name);
			Animal* new_arr = new Animal[amount_animals + 1];

			for (int i = 0; i < amount_animals; i++)
			{
				new_arr[i] = animals[i];
			}
			new_arr[amount_animals] = check_kind_of_animal(kind_of_animal, name);
			delete[] this->animals;
			animals = new_arr;
			amount_animals++;
			cout << "The animal was added successfully.\n\n";
		}
		catch (const string& ex)
		{
			cout << ex;
		}
	}
}

void Zoo::add_worker(const string& name)
{
	if (amount_workers == 0)
	{
		amount_workers++;
		workers = new ZooWorker[amount_workers]{};
		ZooWorker wrkr(name);
		workers[amount_workers - 1] = wrkr;                       
	}
	else if (amount_workers > 0)
	{
		ZooWorker wrkr(name);
		ZooWorker* new_arr = new ZooWorker[amount_workers + 1];
		for (int i = 0; i < amount_workers; i++)
		{
			new_arr[i] = workers[i];
		}
		new_arr[amount_workers] = wrkr;
		delete[] this->workers;
		workers = new_arr;
		amount_workers++;
	}
}

void Zoo::add_camera()
{
	if (amount_cctv_cameras == 0)
	{
		amount_cctv_cameras++;
		cctv_cameras = new VideoCamera[amount_cctv_cameras]{};
		VideoCamera vk;
		vk.set_id(amount_cctv_cameras);
		cctv_cameras[amount_cctv_cameras - 1] = vk;
	}
	else if (amount_cctv_cameras > 0)
	{
		VideoCamera vk;
		vk.set_id(amount_cctv_cameras + 1);
		VideoCamera* new_arr = new VideoCamera[amount_cctv_cameras + 1];
		for (int i = 0; i < amount_cctv_cameras; i++)
		{
			new_arr[i] = cctv_cameras[i];
		}
		new_arr[amount_cctv_cameras] = vk;
		delete[] this->cctv_cameras;
		cctv_cameras = new_arr;
		amount_cctv_cameras++;
	}
}

Animal& Zoo::get_list_of_animals() const
{
	return *animals;
}

ZooWorker& Zoo::get_list_of_workers() const
{
	return *workers;
}

VideoCamera& Zoo::get_list_of_cctv_cameras() const
{
	return *cctv_cameras;
}

void Zoo::show_all_animals() const
{
	if (amount_animals == 0)
	{
		throw string("There are no animals yet, you should add some animal.\n\n");
	}
		
	for (size_t i = 0; i < amount_animals; i++)
	{
		cout << i + 1 << ". " << /*typeid(animals[i]).name() + 6 <<?????????*/ animals[i].get_kind() << " " << animals[i].get_name() << endl;
	}
}

void Zoo::show_all_workers() const
{
	if (amount_workers == 0)
	{
		throw string("There are no workers yet, you should add some worker.\n\n");
	}

	for (size_t i = 0; i < amount_workers; i++)
	{
		cout << i + 1 << ". " << workers[i].get_zoo_worker_name();
		if (!workers[i].get_already_watching())
		{
			cout << "\tfree" << endl;
		}
		else
		{
			cout << "\tbusy" << endl;
		}
	}
}

void Zoo::show_all_cctv_cameras() const
{
	if (amount_cctv_cameras == 0)
	{
		throw string("There are no cctv camera yet, you should add some cctv camera.\n\n");
	}

	for (size_t i = 0; i < amount_cctv_cameras; i++)
	{
		cout << "id. " << cctv_cameras[i].get_id();
		if (!cctv_cameras[i].get_already_watching())
		{
			cout << "\tfree" << endl;
		}
		else
		{
			cout << "\tbusy" << endl;
		}
	}
}

Zoo::~Zoo()
{
	if (animals != nullptr)
	{
		delete[] animals;
	}
	if (workers != nullptr)
	{
		delete[] workers;
	}
	if (cctv_cameras != nullptr)
	{
		delete[] cctv_cameras;
	}
}


