#include <iostream>
#include "Point.h"

int main()
{
    std::cout << "Count  of points : " << Point::getCountPoints() << std::endl; // 0
    Point ZeroPoint(0, 0);
    Point pointA(1, 5);
    Point pointB(3, 10);
    Point pointC;
    Point clone = pointA; // not  counts
    std::cout << "Count  of points : " << Point::getCountPoints() << std::endl; // 3


    pointA.print(); // this = address of object  pointA
    pointB.print(); // 
    clone.print();
    pointC.print();

    std::cout << "Distance between A  and C : " << Point::distance(pointA, pointC) << std::endl << std::endl;

    std::cout << "Comparison between A  and B : " << Point::compair_distance(ZeroPoint, pointA, pointB) << std::endl << std::endl;

    std::cout << "----------------------------------------------------------------------------------------------------------------\nOverload:\n" << std::endl;

    Point pointD(0, 0);
    pointD = pointA + pointB;
    pointD.print();
    std::cout << std::endl;

    bool a = pointA == pointB;
    std::cout << a << std::endl;

    pointA.print();

	

    std::cout << std::endl;
    pointA += 3;
    pointA.print();

	std::cout << std::endl;
	pointA *= 3;
	pointA.print();
}
   

/*
Перевантажити для класу Point операції
бінарний + , повертається новий об'єкт Точки, відповідні координати точок додаються, н-д (1, 2) + (5, 10) --- (6, 12 )
порівняння точок == , !=
унарний - , повертається новий об'єкт Точки,  координати змінюють знак
+= число, збільшуються координати точки(обидві на вказане число)
*= число, домножуються координати точки(обидві на вказане число)*/
