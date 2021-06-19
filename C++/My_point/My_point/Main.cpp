#include<iostream>
#include<math.h>
#include "ctime"
#include "iomanip"
#include <conio.h>
#include <windows.h>
#include "point.h"

int main() {

	std::cout << "Count of points: " << point::get_count_points() << std::endl;

	point pA(3,15);
	point pB(7, 15);
	point pC;
	//point pD(pA);

	std::cout << "Count of points: " << point::get_count_points() << std::endl;

	pA.print();
	pB.print();
	pC.print();
	//pD.print();   // copy by point A. Counter doesn't work, because we don't write it in the copy constructor. Name point D is A, because it copy of point A 

	std::cout << "\nDistance between two points A & B are: " << point::distance(pA, pB) << std::endl;
	std::cout << "\nComparison between two points A & B are: " << point::comparison_two_points(pC, pA, pB) << std::endl;


	system("Pause");
	system("Cls");

	point::init_water();
	point* points[] = { &pA, &pB, &pC };

	for (size_t i = 0; i < sizeof(points)/sizeof(point *); i++)
	{
		points[i]->put_point_on_water();
	}

	point::print_water();
}