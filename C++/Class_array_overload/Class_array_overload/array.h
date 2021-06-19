#pragma once
class array {

public:
	explicit array(size_t size = 1, int value = 0);         // constructor  --- explicit - we don't allowed to convert data  
	array(const array& other);                     // copy constructor
	~array();                                      // destructor
	void print() const;                                   
	void fill_rand();
	void fill_arr(int value);
	//array operator +();                           // overload operator "+" --- unary operation --- only THIS - left part
	array operator + (array& other) const;                // overload operator "+" --- binary operation
	array operator + (int value)const;                   // overload operator "+" --- binary operation --- increase all elements by a value
	bool operator == (array& other);					// overload operator "==" --- binary operation --- comparison of two objects
	bool operator != (array& other);                   // overload operator "!=" --- binary operation --- comparison of two objects
	array operator -() const;                          // overload operator "-" --- unary operation --- change all values on the opposite 
	array& operator ++();                              // overload operator "++" - prefix increment - return object (&)
	array operator ++(int);                            // overload operator "++" - postfix increment - int fictitious value - return copy object
	int &operator [] (size_t index);                    // overload operator "[]" - binary operation - we give the specific index, which we want to change

private:
	size_t size; // count of elements
	int* arr;    // dynamic array

	};

