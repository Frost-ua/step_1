//#pragma once
//#include "Bear.h"
#include "ZooWorker.h"
#include "VideoCamera.h"

class Zoo
{
public:
	Zoo();
	size_t get_amount_animals() const;
	size_t get_amount_workers() const;
	size_t get_amount_cctv_cameras() const;

	Animal& check_kind_of_animal(const string& kind_of_animal, const string& name);
	void add_animal(const string& kind_of_animal, const string& name);
	void add_worker(const string& name);
	void add_camera();
	Animal& get_list_of_animals() const;
	ZooWorker& get_list_of_workers() const;
	VideoCamera& get_list_of_cctv_cameras() const;
	void show_all_animals() const;
	void show_all_workers() const;
	void show_all_cctv_cameras() const;

	~Zoo();

	
private:
	size_t amount_animals = 0;
	size_t amount_workers = 0;
	size_t amount_cctv_cameras = 0;
	Animal* animals = nullptr;
	ZooWorker* workers = nullptr;
	VideoCamera* cctv_cameras = nullptr;
};


