#include <ctime>
#include <iostream>
#include "conio.h"
#include "room.h"
#include "Game_word.h"
#include "Auto.h"
#include "Matrix.h"
#include "VideoCamera.h"
#include "ZooWorker.h"
#include "lib.h"
#include "Menu.h"
#include "water.h"
#include "Archer.h"
#include "Swordsman.h"
#include "Mage.h"
#include "Team.h"
#include "Game.h"
#include "Grandpa.h"
#include"Daddy.h"
#include"Son.h"
#include "tv.h"
#include "remote.h"
#include "String.h"
#include "TeamLeader.h"
//#include "group.h"               // for #pragma region Class_Pupil_+_Group
//#include "pupil.h"               // #pragma region CW_initializer_list_+_pair_+_tuple
#include "Bullet.h"
#include "Magazine.h"
#include "Gun.h"
#include "Queue.h"
#include "FwdList.h"
#include "DList.h"
#include<deque>
#include<algorithm>
#include <list>
#include "Date.h"
#include "OffensesDatabase.h"
#include"Vocabuary.h"
#include<fstream>
#include"FileWorker.h"
#include "Library.h"
#include "Ship_.h"
#include "singleDeckShip.h"
#include "doubleDeckShip.h"
#include "threeDeckShip.h"
#include "fourDeckShip.h"
#include "Fleet.h"
#include "Field.h"
#include "Map.h"
#include "Tower.h"
#include "Fortress.h"
#include "Catapult.h"


using namespace std;

void menu() {
	cout << "1. Add a pupil to the group\n2. Show all pupils \n3. Search a pupil by name\n4. Delete a pupil from group by name\n0. Exit\n\n" << endl;
}

double SquereTriangle(double a, double b, double c) {

	if (a <= 0)
		throw a;
	else if (b <= 0)
		throw b;
	else if (c <= 0)
		throw c;

	if (a >= b + c)
		throw string("This triangle cannot exist.\nSide a (" + to_string(a) + ") >= side b (" + to_string(b) + ") + side c (" + to_string(c) + ")");
	if (b >= a + c)
		throw string("This triangle cannot exist.\nSide b (" + to_string(b) + ") >= side a (" + to_string(a) + ") + side c (" + to_string(c) + ")");
	if (c >= a + b)
		throw string("This triangle cannot exist.\nSide c (" + to_string(c) + ") >= side a (" + to_string(a) + ") + side b (" + to_string(b) + ")");

	double p = (a + b + c) / 2;
	return  sqrt(p * (p - a) * (p - b) * (p - c));
}

pair<int, int> foo(initializer_list < int > list) {

	int min = list.begin()[0];
	int max = list.end()[0];

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list.begin()[i] > max)
			max = list.begin()[i];

		if (list.begin()[i] < min)
			min = list.begin()[i];
	}

	return { min, max };
}

pair<int, int> findDigit(const string & list) {

	auto first = list.find_first_of("0123456789");
	auto last = list.find_last_of("0123456789");
	
	return { first, last };
}

bool isValidOctet(const string& octet) {

	if (empty(octet))
	{
		return false;
	}

	if (octet.begin()[0] == '0' && octet.size() > 1)
	{
		return false;
	}

	for (size_t i = 0; i < octet.size(); i++)
	{
		if (octet[i] < '0' || octet[i] > '9')
		{
			return false;
		}
	}

	if (octet < "0" || octet > "255")
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool checkIP(const string& ip) {

	size_t count = 0;
	for (size_t i = 0; i < ip.size(); i++)
	{
		if (ip.begin()[i] == '.')
			count++;
	}
	if (count != 3)
		return false;

	size_t dot_1_pos = ip.find(".");
	size_t dot_2_pos = ip.find(".", dot_1_pos + 1);
	size_t dot_3_pos = ip.find(".", dot_2_pos + 1);
	string first_octet = ip.substr(0, dot_1_pos);
	string second_octet = ip.substr(dot_1_pos + 1, dot_2_pos - (dot_1_pos + 1));
	string thirth_octet = ip.substr(dot_2_pos + 1, dot_3_pos - (dot_2_pos + 1));
	string fourth_octet = ip.substr(dot_3_pos + 1);

	return (isValidOctet(first_octet) && isValidOctet(second_octet) && isValidOctet(thirth_octet) && isValidOctet(fourth_octet));
}

template<class ContType>
void print(const ContType& container, const string & message = "") 
{
	cout << message << endl;
	for (const auto& e : container)
	{
		cout << e << "\t";
	}
	cout << endl;
}


int main() {
	srand(unsigned int(time(NULL)));

#pragma region Class_Room

	/*std::cout << "r_1 " << std::endl;
	room r_1(10, 8, room::SOUTH);
	r_1.print_room_info();

	std::cout << "r_2 " << std::endl;
	room r_2;
	r_2.print_room_info();

	std::cout << "r_3 = r_1 + r_2: " << std::endl;
	room r_3 = r_1 + r_2;
	r_3.print_room_info();

	std::cout << "r_4 = r_1 + value: " << std::endl;
	room r_4 = r_1 + 2.5;
	r_4.print_room_info();

	std::cout << "r_5 = r_1 - value: " << std::endl;
	room r_5 = r_1 - 3;
	r_5.print_room_info();

	std::cout << "r_6 = r_1 * value: " << std::endl;
	room r_6 = r_1 * 3;
	r_6.print_room_info();

	std::cout << "++r_6 : " << std::endl;
	r_6.set_quarter(room::WEST);
	(++r_6).print_room_info();

	r_6++;
	std::cout << "r_6++ : " << std::endl;
	r_6.print_room_info();

	std::cout << "--r_6 : " << std::endl;
	(--r_6).print_room_info();

	r_6--;
	std::cout << "r_6-- : " << std::endl;
	(r_6).print_room_info();

	std::cout << "r_6 == r_1 : " << std::boolalpha << (r_6 == r_1) << std::endl;
	std::cout << "r_6 != r_1 : " << std::boolalpha << (r_6 != r_1) << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	std::cout << "r_6 > r_1 : " << std::boolalpha << (r_6 > r_1) << std::endl;
	std::cout << "r_6 < r_1 : " << std::boolalpha << (r_6 < r_1) << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	std::cout << "r_1 += value: " << std::endl;
	r_1 += 5;
	r_1.print_room_info();

	std::cout << "r_1 *= value: " << std::endl;
	r_1 *= 2;
	r_1.print_room_info();*/

#pragma endregion

#pragma region Class_Water_+_exceptions

/*
	string name;
	double width = 0, length = 0, maxDepth = 0;
	int choose = 0;
	water::typeWater type;

	while (true)
	{
		cout << "Choose type of water:\n1. Lake\n2. Channel\n3. Basin\n";
		cin >> choose;
		switch (choose)
		{
		case 1: {
			type = water::LAKE;
			break;
		}
		case 2: {
			type = water::CHANNEL;
			break;
		}
		case 3: {
			type = water::BASIN;
			break;
		}
		default:
			type = water::LAKE;
			break;
		}

		cout << "Enter name of water: ";
		cin >> name;
		cout << "Enter width of water (min 3): ";
		cin >> width;
		cout << "Enter length of water (min 4): ";
		cin >> length;
		cout << "Enter max depth of water (min 1): ";
		cin >> maxDepth;

		try
		{
			water julia(name, width, length, maxDepth, type);
			julia.print_info();
		}
		catch (const WrongWidthException& ex)
		{
			cout << ex.get_error();
		}
		catch (const WrongLengthException& ex)
		{
			cout << ex.get_error();
		}
		catch (const WrongDepthException& ex)
		{
			cout << ex.get_error();
		}
	}




	water julia("Julia", 115, 75, 5, water::LAKE);
	julia.print_info();
	julia.add_water_to_group();

	water olivia("Olivia", 19, 55, 51, water::CHANNEL);
	olivia.print_info();
	olivia.add_water_to_group();

	water inga("Inga", 61, 28, 7, water::LAKE);
	inga.print_info();
	inga.add_water_to_group();

	water viktoria("Victoria", 512, 1256, 48, water::LAKE);
	viktoria.print_info();
	viktoria.add_water_to_group();

	water nadiya("Nadya", 125, 785, 21, water::LAKE);
	nadiya.print_info();
	nadiya.add_water_to_group();

	water marina("Marina", 71, 129, 1.5, water::SWAMP);
	marina.print_info();
	marina.add_water_to_group();

	cout << "\n" << water::Search_bigest_water(water::LAKE).get_name() << " --- is the biggest ";
	water::Search_bigest_water(water::LAKE).show_water_type();

	cout << "\n\nNumber of waters: " << water::count << "\n\n";

	cout << "Square of " << julia.get_name() << " : " << julia.water_squere() << " m^2" << "\n";
	cout << "Square of " << olivia.get_name() << " : " << olivia.water_squere() << " m^2" << "\n\n";
	cout << "Volume of " << julia.get_name() << " : " << julia.water_volume() << " m^3" << "\n";
	cout << "Volume of " << olivia.get_name() << " : " << olivia.water_volume() << " m^3" << "\n\n";

	cout << "Type of water --- " << julia.get_name() << " == " << olivia.get_name() << " --- " << boolalpha << water::compare_type_water(julia, olivia) << "\n\n";

	cout << "Comparison between the areas of two waters:\t";

	if (water::compare_water_squere(julia, olivia) == 1)
	{
		cout << julia.get_name() << " is bigger than " << olivia.get_name() << "\n\n";
	}
	if (water::compare_water_squere(julia, olivia) == -1)
	{
		cout << julia.get_name() << " is smaller than " << olivia.get_name() << "\n\n";
	}
	if (water::compare_water_squere(julia, olivia) == 0)
	{
		cout << julia.get_name() << " has the same area as " << olivia.get_name() << "\n\n";
	}*/
#pragma endregion

#pragma region Class_Pupil_+_Group

/*
group gr_cpp("ITStep-23");
gr_cpp.set_pupil_to_group("Alex", "Frost", "Rivne");

menu();

while (true)
{
	switch (_getch())
	{
	case '1': {
		system("Cls");
		menu();
		string name, surname, city;
		cout << "Enter the name:" << endl;
		cin >> name;
		cout << "Enter the surname:" << endl;
		cin >> surname;
		cout << "Enter the city:" << endl;
		cin >> city;
		gr_cpp.set_pupil_to_group(name, surname, city);
		system("Cls");
		menu();
		break;
	}
	case '2': {
		system("Cls");
		menu();
		gr_cpp.print_group_info();
		break;
	}
	case '3': {
		system("Cls");
		menu();
		string name;
		cout << "Enter the name for searching:" << endl;
		cin >> name;
		system("Cls");
		menu();
		cout << gr_cpp.search_pupil(name) << endl << endl;
		break;
	}
	case '4': {
		system("Cls");
		menu();
		string name;
		cout << "Enter the name for deleting:" << endl;
		cin >> name;
		if (gr_cpp.delete_pupil(name))
		{
			cout << "\n" << name << " was deleted from the group.\n" << endl;
		}
		else
		{
			cout << "\n" << name << " isn't found\n" << endl;

		}

		//gr_cpp.print_group_info();
		break;
	}
	case '0': {
		return 0;
	}
	default: {
		system("Cls");
		cout << "You entered incorrect value. Enter value from 0 to 4." << endl;
		break;
	}
	}
}*/


#pragma endregion

#pragma region Class_tv_+_remote

/*
tv sony;
cout << "Sony" << endl;
sony.show();
remote r_sony(&sony);
r_sony.power(true);
cout << "Sony" << endl;
sony.show();
tv lg(true, 100, 100, 12, 10);
cout << "LG" << endl;
lg.show();
remote r_lg(&lg);
r_lg.go_channel(76);
cout << "LG" << endl;
lg.show();
r_lg.set_remote(&sony);
r_lg.go_channel(82);
cout << "Sony" << endl;
sony.show();
cout << "LG" << endl;
lg.show();
cout << "Sony" << endl;
++r_lg;
+r_lg;
--r_lg;
-r_lg;*/


//=============================================================
/*
cout << "\t\t\tTV menu:" << endl;
tv sony;
while (true)
{
	cout << "1. Turn ON\n2. Turn OFF\n3. Next channel\n4. Previous channel\n5. Increase volume\n6. Decrease volume\n7. Show info\n0. Exit\n\n" << endl;

	switch (_getch())
	{
	case '1': {
		system("Cls");
		sony.power(true);
		break;
	}
	case '2': {
		system("Cls");
		sony.power(false);
		break;
	}
	case '3': {
		system("Cls");
		sony.next_channel();
		break;
	}
	case '4': {
		system("Cls");
		sony.prev_channel();
		break;
	}
	case '5': {
		system("Cls");
		sony.inc_volume();
		break;
	}
	case '6': {
		system("Cls");
		sony.dec_volume();
		break;
	}
	case '7': {
		system("Cls");
		sony.show();
		break;
	}
	case '0': {
		return 0;
	}
	default: {
		system("Cls");
		cout << "You entered incorrect value. Enter value from 0 to 6." << endl;
		break;
	}
	}
}*/

#pragma endregion

#pragma region classes_Swordsman_Archer_Mage

/*
Team team_1("Gnomes", 5);
Team team_2("Orks", 5);

Game battle_1(team_1, team_2);
battle_1.print_map();
battle_1.battle();*/

#pragma endregion

#pragma region Fortress


#pragma endregion

#pragma region Inheritance_classes_Employee_+_Production_worker_+_Team_leader

/*
ProductionWorker bob("Bob", "12-02-2008", ProductionWorker::NIGHT, 15.5, 48);
ProductionWorker freddie("Freddie", "06-10-2012", ProductionWorker::NIGHT, 12, 52);
ProductionWorker jack("Jack", "25-06-2018", ProductionWorker::DAY, 10.2, 82);
TeamLeader george("George", "12-08-2018", ProductionWorker::DAY, 55, 49, 750, 32, 25, 4);

bob.print_employee_info();
freddie.print_employee_info();
jack.print_employee_info();
george.print_employee_info();
george.add_worker(jack);
george.add_worker(bob);
george.add_worker(freddie);
george.print_workers_list();
george.print_team_leader_info();*/

#pragma endregion

#pragma region class_String

/*
cout << "str_1:" << endl;
String str_1("Microsoft");
str_1.output_str();

cout << "\n------------------------------------------------\nstr_2:" << endl;
String str_2("Windows");
str_2.output_str();

cout << "\n------------------------------------------------\nstr_3 = str_1 + str_2:" << endl;
String str_3 = str_1 + str_2;
str_3.output_str();

cout << "\n------------------------------------------------\nstr_4 = str_1 * str_2: - the same symbols" << endl;
String str_4 = str_1 * str_2;
str_4.output_str();

cout << "\n------------------------------------------------\nstr_5 = str_1 / str_2: - the different symbols" << endl;
String str_5 = str_1 / str_2;
str_5.output_str();

cout << "\n------------------------------------------------\nstr_6 = str_1 + \"text\": " << endl;
String str_6 = str_1 + " Teams";
str_6.output_str();

cout << "\n------------------------------------------------\nstr_7 = \"text\" + str_2: " << endl;
String str_7 = String::str_concat("Vista ", str_2);
str_7.output_str();

cout << "\n------------------------------------------------\n++str_2: increase each symbols (prefix)" << endl;
++str_2;
str_2.output_str();

cout << "\n------------------------------------------------\nstr_2++: increase each symbols (postfix)" << endl;
str_2++;
str_2.output_str();

cout << "\n------------------------------------------------\nstr_1 > str_2: - compare two strings" << endl;
bool a = str_1 > str_2;
cout << boolalpha << a;

cout << "\n------------------------------------------------\nstr_1 < str_2: - compare two strings" << endl;
bool b = str_1 < str_2;
cout << boolalpha << b;

cout << "\n------------------------------------------------\nstr_1 >= str_2: - compare two strings" << endl;
bool c = str_1 >= str_2;
cout << boolalpha << c;

cout << "\n------------------------------------------------\nstr_1 <= str_2: - compare two strings" << endl;
bool d = str_1 <= str_2;
cout << boolalpha << d;

cout << "\n------------------------------------------------\nstr_1 == str_2: - compare two strings" << endl;
bool e = str_1 == str_2;
cout << boolalpha << e;

cout << "\n------------------------------------------------\nstr_1 != str_2: - compare two strings" << endl;
bool f = str_1 != str_2;
cout << boolalpha << f;

cout << "\n------------------------------------------------\nrevers of str_1: " << endl;
String str_8 = !str_1;
str_8.output_str();

cout << "\n------------------------------------------------\nindex[0] of str_1" << endl;
cout << str_1[0];

cout << "\n------------------------------------------------\nchange symbol of str_1 by index [0] = \"X\": " << endl;
str_1[0] = 'X';
str_1.output_str();

cout << "\n------------------------------------------------\nstr_9, operator () - show particular symbols of str_9: - from 2-d symbol plus 4 symbols" << endl;
String str_9("Beautiful");
str_9.output_str();
cout << endl;
str_9(2, 4).output_str();

cout << "\n------------------------------------------------\nint(str_10) - to integer, only digit: " << endl;
String str_10("2020");
cout << int(str_10);


cout << "\n------------------------------------------------\ncout << str_9:" << endl;
cout << str_9;

cout << "\n------------------------------------------------\ncin >> str_9:" << endl;
cin >> str_9;
cout << "------------------------------------------------\ncout << str_9:" << endl;
cout << str_9;

cout << endl << endl;*/

#pragma endregion

#pragma region Classes_Grandpa_Daddy_Son

/*
const size_t SIZE = 3;
Grandpa* family[SIZE] = { new Grandpa("Elvis", 84), new Daddy("Freddie", 42), new Son("Robert", 14, 2) };

cout << "_____________ dynamic_cast_____________\n\n";
PrintFamily_dynamic_cast(family, SIZE);

cout << "\n\n_____________ static_cast _____________\n\n";
PrintFamily_static_cast(family, SIZE);

cout << "\n\n_____________ const_cast _____________\n\n";
Son jeck("Jeck", 8, 2);
jeck.show_hours_for_walking();*/


#pragma endregion

#pragma region Zoo

	/*Menu menu;
	menu.show_menu();*/

#pragma endregion 

#pragma region Exceptions
	/*double a, b, c;

	while (true)
	{
		try
		{
			cout << "Enter three sides of triangle: ";
			cin >> a >> b >> c;
			cout << "Area of triangle = " << SquereTriangle(a, b, c) << endl << endl;
		}
		catch (const double a)
		{
			cout << "Some side <= " << a << "\n\n";
		}
		catch (const string message)
		{
			cout << message << "\n\n";
		}
	}*/

#pragma endregion

#pragma region Templates_Matrix

/*
	try
	{
		Matrix<int> m(3, 3, 5);
		cout << "Matrix M:";
		m.print();
		cout << "Enter digits:\n";
		cin >> m;
		cout << "\nMatrix M:\n\n";
		cout << m << endl;

		system("Pause");
		cout << "Matrix A: copy ctor  A(M)";
		Matrix<int> a(m);
		a.print();
		system("Pause");

		cout << "Matrix C:";
		Matrix<int>c(4, 4, 5);
		c.print();

		system("Pause");
		cout << "Matrix M: operator ()   M(0,0) = 100";
		m(0, 0) = 100;
		m(1, 2) = 1;
		m.print();

		system("Pause");
		cout << "Matrix A: (operator =) A = M";
		a = m;
		a.print();

		system("Pause");
		cout << "Max element of A:\n" << a.GetMaxElement() << endl;
		cout << "\nMin element of A:\n" << a.GetMinElement() << endl;
		cout << "\nSearch value 1020 in A:\n" << boolalpha << a.SearchValue(1020) << endl;
		cout << "\nSum of A:\n" << a.GetSumElements() << endl;

		system("Pause");
		try
		{
			cout << "\nMatrix B = A + M: (operator +):";
			Matrix<int> b = a + m;
			b.print();
		}
		catch (const std::logic_error& ex)
		{
			cout << "\n" << ex.what() << endl;
		}

		system("Pause");
		cout << "\nMatrix A += 10: (operator +=)";
		a += 10;
		a.print();

		system("Pause");
		cout << "\nMatrix D = A + 2: (operator + (value))";
		Matrix<int> d = a + 2;
		d.print();

		cout << "\nMatrix D = 4 + A: (operator + (value))";
		d = 4 + a;
		d.print();

		system("Pause");
		cout << "\nMatrix D == A: (operator ==)\n" << boolalpha << (d == a) << endl;

		cout << "\nMatrix D != A: (operator !=)\n" << boolalpha << (d != a) << endl;

		system("Pause");
		cout << "\nAdd new row to matrix D:";
		d.addRow();
		d.print();

		cout << "\nAdd new column to matrix D:";
		d.addCol();
		d.print();
		cout << "\nAmounte of matrices:\n";
		cout << m.GetCountObjMatrix() << endl;


		system("Pause");
		system("Cls");

		Matrix<double> a1(3, 3, 5.78);
		a1.print();

		Matrix<string> b1(3, 3, "Str");
		b1.print();

		Matrix<string> c1(3, 3, "My ");
		Matrix<string> d1 = c1 + b1;
		d1.print();

		d1.addCol("Hello!");
		d1.addRow("World");
		d1.print();


	}
	catch (WrongMatrixPrameters& ex)
	{
		ex.get_err_message();
	}
	catch (const out_of_range& ex)
	{
		cout << ex.what() << endl;
	}*/


#pragma endregion

#pragma region Exceptions_class_Auto

	/*try
	{
		char car_number[25]{};
		bool exit = true;
		size_t current_speed, max_speed;
		cout << "Enter car number: ";
		cin >> car_number;
		cout << "Enter current speed: ";
		cin >> current_speed;
		cout << "Enter max speed: ";
		cin >> max_speed;

		Auto bmw(car_number, current_speed, max_speed);

		while (exit)
		{
			bmw.print_car_info();
			cout << "\n1. Increase speed.\n2. Decrease speed.\n\n";

			switch (_getch())
			{
			case '1': {
				bmw.increase_speed(current_speed);
				system("Cls");
				break;
			}

			case '2': {
				bmw.decrease_speed(current_speed);
				system("Cls");
				break;
			}
			case 0: {
				exit = false;
				break;
			}
			default: {
				cout << "Incorrect value!\n";
				break;
			}
			}
		}
	}
	catch (InvalidNumberException& ex) {
		ex.get_err_message();
	}
	catch (WrongSpeedException& ex) {
		ex.get_err_message();
	}
	catch (WrongMaxSpeedException& ex) {
		ex.get_err_message();
	}*/

#pragma endregion

#pragma region CW_initializer_list_+_pair_+_tuple

/*
auto res = foo({ 25, 14, 4, 74, 52, 15 });

cout << "Min = " << res.first << endl;
cout << "Max = " << res.second << endl;

// ==================   Task #1   ==================== 

cout << "===  TASK #1   ===\n\n";
cout << "Find the position of digits in the string: Baker Street, 221b\n\n";
auto result = findDigit("Baker Street, 221b");
cout << result.first << endl;
cout << result.second << endl;
cout << "\n";
system("Pause");
system("cls");

// ==================   Task #2   ====================

cout << "===  TASK #2   ===\n\n";
pupil jordy("Jordy", "Frost", "London", { 5, 12, 8, 3, 6 });    // create new pupil "Jordy" --- use new ctor with initializer_list   ---  
jordy.print_pupil_info();
pupil alex("Alex", "Frost", "London", 3);                      // create new pupil "Alex" --- use old ctor with amount of marks
alex.print_pupil_info();

jordy.set_mark(5, 10);                                         // set new mark 10, position 5 for pupil Jordy
jordy.print_pupil_info();
cout << "\n\n";
system("Pause");
system("cls");

// ==================   Task #3   ====================

cout << "===  TASK #3   ===\n\n";
cout << "Check IP:\n\n";
string ip;
cout << "Enter ip address:\n";
getline(cin, ip);

if (checkIP(ip))
{
	cout << "IP is correct.\n\n";
}
else
{
	cout << "IP isn't correct.\n\n";
}
system("Pause");
system("cls");

// ==================   Task #4   ====================

cout << "===  TASK #4   ===\n\n";
cout << "Game: Wheel of Fortune\n\n";

Game_word game;
game.run();*/

#pragma endregion

#pragma region STACK_Gun_+_magazine_+_bullets

/*
// =========  TASK #1   =========
try
{
	Queue<int>a;
	a.push(15);
	a.push(-15);
	a.push(458);
	a.push(12);
	a.push(78);
	//a.push(78);
	a.print();

	a.pop();
	a.print();
	cout << "\nFirst element : ";
	cout << a.front() << endl << endl;
}
catch (const std::out_of_range& ex)
{
	cout << ex.what();
}
system("Pause");
system("Cls");
// =========  TASK #2   =========
Gun m_13;
while (m_13.getMagazine().getAmountBullets() != 0)
{
	m_13.shoot();
}
m_13.shoot();*/

#pragma endregion

#pragma region FwdList_+_DList

//================   Forvard List   =====================

/*
FwdList<int> a;
a.pushFront(10);
a.pushFront(20);
a.print();*/



//================   Double - linked list   ==================== =

/*
cout << "\n===   List C:   -------------------------------\n";
DList<int> c;
c.pushBack(102);
c.pushBack(512);
c.pushBack(75);
c.pushBack(56000);
c.pushBack(400);
c.print();
c.printR();

cout << "\n===   After push front (100) List C:   -------------------------------\n";
c.pushFront(100);
c.print();
c.printR();

cout << "\n===   After pop back List C:   -------------------------------\n";
c.popBack();
c.print();
c.printR();

cout << "\n===   After pop front List C:   -------------------------------\n";
c.popFront();
c.print();
c.printR();

cout << "\n===   After delete particular data (75) List C:   -------------------------------\n";
c.deleteData(75);
c.print();
c.printR();

cout << "\n===   After insert data before particular data (69 before 102) List C:   -------------------------------\n";
c.insertBefore(102, 69);
c.print();
c.printR();

cout << "\n===   After insert data after particular data (750 after 69) List C:   -------------------------------\n";
c.insertAfter(69, 750);
c.print();
c.printR();

cout << "\n===   After operation + list D (12, 89):   -------------------------------\n";
DList<int> d;
d.pushBack(12);
d.pushBack(89);

cout << "\n===   List F = C + D:   -------------------------------\n";
DList<int> f = c + d;
cout << "\n===   List F:   -------------------------------\n";
f.print();
f.printR();
cout << "\n===   List C:   -------------------------------\n";
c.print();
c.printR();
cout << "\n===   List D:   -------------------------------\n";
d.print();
d.printR();

cout << "\n===   After operation += List F += D  :   -------------------------------\n";
f += d;
f.print();
f.printR();

cout << "\n===   After replace data (all 89 was changed by 2006) List F:   -------------------------------\n";
size_t count = f.replaceData(89, 2006);
f.print();

cout << "Number of replacements steps : " << count << "\n";

cout << "\n===   After operation * --- List N contains the same data in K and M without repeat :   -------------------------------";
cout << "\n===   List K:   -------------------------------\n";
DList<int> k;
k.pushBack(12);
k.pushBack(12);
k.pushBack(1200);
k.pushBack(580);
k.pushBack(36);
k.print();
cout << "\n===   List M:   -------------------------------\n";
DList<int> m;
m.pushBack(120);
m.pushBack(500);
m.pushBack(12);
m.pushBack(12);
m.pushBack(36);
m.print();
cout << "\n===   List N:   -------------------------------\n";
DList<int> n = k * m;
n.print();
n.printR();

cout << "\n===   After cleaning list N:   -------------------------------\n";
n.deleteList();
n.print();
n.printR();

cout << "\n===   After rotate list F:   -------------------------------\n";
f.print();
f.rotateList();
f.print();
f.printR(); */

#pragma endregion

#pragma region CW_Algorithms

/*
deque<int> d{ 10,5,100 };
d.push_front(7);
d.push_back(3);
d.insert(d.begin() + 3, { 20, 21, 22 });
print(d, "Deque : ");*/

/*
cout << "Revers --- print deque in revers order : \n";
for (int i = d.size() - 1; i < i >= 0; i--)
{
	cout << d[i] << "\t";
}
cout << endl;*/

/*
for (auto it = d.rbegin(); it != d.rend(); it++)
{
	cout >> it->
}*/




/*
random_shuffle(d.begin(), d.end());  //
print(d, "Deque after shuffle : ");


list<int> li;
li.resize(d.size());//copy(d.begin(), d.end(), li.begin());
auto iter = copy(d.begin(), d.begin() + d.size() / 2, li.begin());
copy(d.rbegin(), d.rbegin() + d.size() / 2, iter);
print(li, "List :");


int value;
cout << "\nEnter element for search : ";
cin >> value;
iter = find(begin(li), end(li), value);

if (iter != end(li))
{
	cout << "Found value " << value << " in index " << distance(begin(li), iter) << endl;
}
else
{
	cout << "Not found value! \n";
}*/

/*
int amount = 7;
deque<int> d(amount);

int left = -10, right = 10;
auto lam = [&]() {return left + rand() % (right - left + 1); };
generate(d.begin(), d.end(), lam);
print(d);
int div = 2;
auto it = find_if(begin(d), end(d), [div](int element) {return element % div == 0; });
if (it != end(d))
{
	cout << "Found number divisible on " << div << "[" << *it << "] in index " << 
	it - begin(d) << "\n";
}

cout << "Count of positive elements : " << count_if(begin(d), end(d), [](int e) {return e > 0; }) << endl;

cout << "=======================================================/n/n";

deque<string> c({"Apple", "Orange", "Banana", "Apple"});
print(c);

cout << "\nCount of the same words : " << count(begin(c), end(c), "Apple") << endl;
char e = 'a';
cout << "\nCount of words with letter \"a\" : " << count_if(begin(c), end(c), [&e](string elem) {return elem.find(e) != -1; }) << endl;

cout << "\nAfter sorting by decrease ";
sort(rbegin(c), rend(c));
print(c);

cout << "\nAfter sorting by decrease of size:";
sort(c.begin(), c.end(), [](string str_1, string str_2) { return str_1.size() < str_2.size(); });
print(c);
*/





// Створити deque з рядків. Вивести дек.
/*
1. Знайти кількість повторів певного слова - count + lambda
2. Знайти кількість слів з буквою `а` count_if + lambda
3. впорядкувати дек за спаданням sort
4. впорядкування за довжиною слів( по зростанню довжин) sort(begin(d), end(d), [] (string s1, string 2) {​​.....}​​)
*/




#pragma endregion

#pragma region  Binary_tree

/*
OffensesDatabase a;

Date d_1(23, 01, 2021);
Date d_2(02, 02, 2021);
Date d_3(15, 02, 2021);
Date d_4(23, 03, 2021);
Date d_5(10, 05, 2021);

Violetion v_1("Exceeding the speed limit", d_1, 120);
Violetion v_2("Exceeding the speed limit", d_2, 120);
Violetion v_3("Exceeding the speed limit", d_3, 250);
Violetion v_4("Driving at a red light", d_4, 175);
Violetion v_5("Driving at a red light", d_5, 175);
Violetion v_6("Driving at a red light", d_3, 260);
Violetion v_7("Driving without a seat belt", d_1, 80);
Violetion v_8("Driving without a seat belt", d_2, 80);
Violetion v_9("Drunk driving", d_4, 1750);
Violetion v_10("Drunk driving", d_5, 2550);
Violetion v_11("Drunk driving", d_1, 3700);

a.add("KN 2569 VC", v_1);
a.add("CH 1537 FF", v_2);
a.add("ON 4456 PO", v_3);
a.add("FLO 125 I", v_1);
a.add("GHY 225 D", v_10);
a.add("IU 2569 FR", v_11);
a.add("FLO 125 I", v_5);
a.add("TEX 125 OI", v_7);
a.add("CH 1537 FF", v_8);
a.add("ER 8969 JJ", v_6);

cout << "\t\t\t\t===== Print all cars =====\n\n";
a.printAll();

system("Pause");
system("Cls");
cout << "\t\t\t\t===== Print specific car =====\n\n";
a.printSpecificCar("FLO 125 I");

system("Pause");
system("Cls");
cout << "\t\t\t\t===== Print range of car numbers =====\n\n";

a.printRange("F", "G");*/

#pragma endregion

#pragma region Set_Map

/*
Vocabuary a;
a.print();
cout << "Translation of the word \"Book\" is ";
a.searchTranslate("Book");
cout << "After deleting the word \"Apple\":\n";
a.deleteWord("Apple");
a.print();
cout << "After adding the word \"Dog\":\n";
a.addWord("Dog", "Pes");
a.print();
cout << "After editing the word \"Dog\", and reading all words from the file:\n";
a.editWord("Dog", "Sobaka");
a.writeTextToFile();
a.printTextFromFile();*/

#pragma endregion

#pragma region Work_with_files

/*
ifstream fin;  // only read
ofstream fout;  // only write   1) rewrite  2) append
fstream file;
string fname = "Demo.xml";

//FileWorker::writeTextFile(fname);
FileWorker::printTextFile(fname);

//FileWorker::copyFile(fname, "Demo_copy.xml"); //copy text from "Demo.xml" to "Demo_copy.xml"

FileWorker::writeTextFile(fname, true); // adding some text to "Demo.xml"
FileWorker::printTextFile(fname);*/
/*
Library lib;

lib.addBook("Joanne Rowling", "Philosopher's Stone ", 1997);
lib.addBook("Jules Verne", "20,000 Leagues Under The Sea", 1870);
lib.addBook("Joanne Rowling", "Chamber of Secrets", 1998);
lib.addBook("Charles Michael Palahniuk", "Fight Club", 1996);
lib.addBook("Joanne Rowling", "Prisoner of Azkaban", 1999);
lib.addBook("Jules Verne", "Around the World in Eighty Days ", 1872);
lib.addBook("Joanne Rowling", "Goblet of Fire", 2000);
lib.addBook("Stephen Edwin King", "11/22/63", 2011);
lib.addBook("Joanne Rowling", "Order of the Phoenix", 2003);
lib.addBook("Stephen Edwin King", "The Shining", 1977);
lib.addBook("Joanne Rowling", "Half-Blood Prince", 2005);
lib.addBook("Stephen Edwin King", "The Green Mile", 1996);
lib.addBook("Joanne Rowling", "Deathly Hallows", 2007);
lib.addBook("Charles Michael Palahniuk", "Survivor", 1999);

cout << "\t\t---===  All books  ===---\n";
lib.printAllBooks();

cout << "\n\t\---===  Search books by author  ===---\n";
lib.searchBookByAuthor("Jules Verne");

cout << "\n\t\---===  Search books in library  ===---\n";
cout << boolalpha << lib.searchBook("Joanne Rowling", "Half-Blood Prince").getAvailable();

cout << "\n\t\---===  Borrow the book in library  ===---\n";
lib.borrowBook("Leo Tolstoy", "War and Peace");
lib.borrowBook("Stephen Edwin King", "11/22/63");

cout << "\n\t\---===  Return the book in library  ===---\n";
lib.returnBook("Stephen Edwin King", "11/22/63");

cout << "\n\t\---===  Delete the book from library  ===---\n";
lib.deleteBook("Joanne Rowling", "Goblet of Fire", 2000);
lib.printAllBooks();

cout << "\n\t\---===  Sort books by author  ===---\n";
lib.sortBook();
lib.printAllBooks();

cout << "\n\t\---===  Edit the book :  \"Half - Blood Prince\" by \"Joanne Rowling\", ===---\n";
lib.editBook("Joanne Rowling", "Half-Blood Prince");
cout << "\n\t---===   Edited library :   ===--- \n";
lib.printAllBooks();

lib.writeLibToFile(false);

cout << "\n==================   Read from file   ==============\n";
Library a;
a.readLibFromFile();
a.printAllBooks();*/

#pragma endregion

#pragma region Battle_sea_EXAM




/*
cout << "===============   4 deck ship\n";
fourDeckShip a;

a.getShip()[Ship_::FIRST].setX(8);
a.getShip()[Ship_::FIRST].setY(2);
cout << a.getShip()[Ship_::FIRST].getX();
cout << a.getShip()[Ship_::FIRST].getY();

a.printShipInfo();*/

/*
Fleet dd;
dd.getFleet()[0].getShip()[0].setX(8);

Map d;
//d.placeEnemyShips();
d.print();

Field ss;*/
/*
for (size_t i = 0; i < 10; i++)
{
	for (size_t j = 0; j < 10; j++)
	{
		cout << ss.getMatrix()[i][j];
	}
	cout << endl;
}
for (size_t i = 0; i < dd.getFleet().size(); i++)
{
	dd.getFleet()[i].printShipInfo();
}*/


#pragma endregion


#pragma region Virtual_inheritance


/*
Fortress fortress(4, 6);
fortress.CtapultShoot();
fortress.ArcherShoot();
fortress.ArcherShoot();
fortress.ArcherShoot();
fortress.RangerShoot();
fortress.RangerShoot();*/



#pragma endregion




return 0;
}

