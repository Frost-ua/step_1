#include <iostream>
#include <string>

using namespace std;

class pupil
{

public:

	pupil(const string& pupil_name, const string& pupil_surname, const string& city, size_t amount_marks);
	pupil(const string& pupil_name, const string& pupil_surname, const string& city, initializer_list<int> list);                // new!

	pupil();

	pupil& operator=(const pupil& other);

	pupil(const pupil& other);

	void set_mark(size_t lesson, size_t mark);
	void setMarks(initializer_list<int> list);                 // new!

	void set_pupil_name(string name);

	void set_pupil_surname(string surname);

	void set_city(string city);

	void set_amount_marks(size_t amount_marks);

	string get_name() const;

	string get_surname() const;

	string get_city() const;

	size_t get_amount_marks() const;

	void print_pupil_info() const;

	~pupil();

private:
	static const size_t MIN_MARK = 0;
	static const size_t MAX_MARK = 12;
	string pupil_name;
	string pupil_surname;
	string city;
	size_t* marks;
	initializer_list<int> marks_list;                         // new!
	size_t amount_marks;
};
