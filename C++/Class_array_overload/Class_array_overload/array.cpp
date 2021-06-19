#include <iostream>
#include "array.h"

array::array(size_t size, int value)             // ctor
{
	if (size == 0)
	{
		size = 1;
	}
	this->size = size;
	arr = new int[size];
	fill_arr(value);
}

array::array(const array& other)                // copy ctor
{
	this->size = other.size;
	arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

array::~array()                                // dtor
{
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
	}
}

void array::print() const                        // print method
{
	std::cout << "Array:"<< " \t";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}

void array::fill_rand()                        // fill random values
{
	
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 101 - 30;
	}
}

void array::fill_arr(int value)                // fill array specific value  
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

array array::operator + (array& other) const         // overload operator "+" --- binary operation THIS -left, other - right
{
	array result(this->size + other.size);     // create new object with name "result" with new size --- THIS size (left argument) + OTHER size (right argument)

	for (size_t i = 0; i < this->size; i++)    // copy all elements of THIS arr to result
	{
		result.arr[i] = this->arr[i];
	}
	for (size_t i = 0; i < other.size; i++)     // copy all elements of OTHER arr to result
	{
		result.arr[i + this->size] = other.arr[i];
	}

	return result;                                // return a new object (his copy)
}

array array::operator + (int value) const               // overload operator "+" --- binary operation THIS -left, some value - right
{
	array result(*this);                          // create new object with name "result" and copy all field from THIS (*) - left part

	for (size_t i = 0; i < this->size; i++)
	{
		result.arr[i] += value;                   // All elements of an result's array increasing by a value 
	}
	return result;                                // return COPY of THIS object (not link)
}

bool array::operator==(array& other)             // overload operator "==" --- binary operation --- comparison of two objects
{
	if (this->size != other.size)                // compare two arrays of objects
		return false;
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] != other.arr[i];
		return false;
	}
	return true;
}

bool array::operator!=(array& other)             // overload operator "==" --- binary operation --- comparison of two objects
{
	return !(*this == other);                   // use operator "=="
}

array array::operator-() const                        // overload operator "-" --- unary operation --- change all values on the opposite 
{
	array result(*this);                              // create new object with name "result" and copy all field from THIS (*) - left part
	for (size_t i = 0; i < result.size; i++)
	{
		result.arr[i] = -result.arr[i];               // assign all elements of array to opposite values
	}
	return result;                                     // return COPY of object "result"
}

array& array::operator++()                              // overload operator "++" - prefix increment - return object (&)
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i]++;                               // we increase all elements of array by 1 (++)
	}

	return *this;                                    // return THIS object (NOT copy)
}

array array::operator++(int)                    // overload operator "++" - postfix increment - int fictitious value - return copy object
{
	array tmp(*this);                           // create tmp object --- copy from THIS - copy ctor
	++* this;                                   // increase THIS by 1
	return tmp;                                 // but return tmp object
}

int &array::operator[](size_t index)             // overload operator "[]" - binary operation - we give the specific index, which we want to change
{
	if (index < size)
		return arr[index];
	
	
	std::cerr << "The index is wrong: " << index << std::endl;
	exit(1);
}
