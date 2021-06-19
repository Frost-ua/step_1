#include <iostream>
#include <string>
#include "pupil.h"

using namespace std;

class group
{
private:
	string group_name = "Noname";
	size_t group_size = 0;
	pupil* arr_group = nullptr;

public:
	group() = default;
	group(const string& group_name, size_t group_size = 0);
	group(const group& other);

	void set_group_name(string group_name);
	group& operator = (const group& other);

	void set_pupil_to_group(string name, string surname, string city);
	void set_pupil_to_group(pupil & pers);
	string search_pupil(string name);
	bool delete_pupil(string name);
	void print_group_info() const;
								
	
	
	~group();

};

