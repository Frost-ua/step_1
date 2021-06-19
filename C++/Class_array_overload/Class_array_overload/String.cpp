#include <iostream>
#include "String.h"

using namespace std;

String::String(const char* str)                  //Ctor
{
	length = strlen(str);
	this->str = new char[length + 1];

	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}

String::String(size_t _length)              //Ctor
{
	length = _length;
	str = new char[length] {};
}
String::String()                             // Default Ctor
{
	length = 80;
	str = new char[length] {};
}

String::String(const String& other)          //Copy Ctor
{
	this->length = strlen(other.str);
	this->str = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
}

String::String(String&& other)                    // Displacement ctor
{
	this->length = other.length;
	this->str = other.str;
	other.str = nullptr;
}

String& String::operator=(const String& other)
{
	if (this->str != nullptr)
	{
		delete[] str;
	}

	length = strlen(other.str);
	this->str = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';

	return *this;
}

String/*&*/ String::operator+(const String& other) const                //----------------------??????????????????????????????
{
	String new_str;
	size_t this_length = strlen(this->str);
	size_t other_length = strlen(other.str);
	new_str.length = this_length + other_length;
	new_str.str = new char[new_str.length + 1];

	size_t i = 0;
	for (; i < this_length; i++)
	{
		new_str.str[i] = this->str[i];
	}

	for (size_t j = 0; j < other_length; j++, i++)
	{
		new_str.str[i] = other.str[j];
	}
	new_str.str[new_str.length] = '\0';

	return new_str;
}

String String::operator+(const char* str) const
{
	String tmp(str);
	String result = *this + tmp;

	return result;
}

String String::str_concat(const char* str, const String& other)
{
	String tmp(str);
	String result = tmp + other;
	return result;
}

String& String::operator++()
{
	for (size_t i = 0; i < Length(); i++)
	{
		str[i]++;
	}
	return *this;
}

String String::operator++(int)
{
	String tmp(*this);
	++*this;
	return tmp;
}

void String::output_str() const           // print string
{
	cout << this->str;
}

void String::input_str(const char* new_str)   // Change string in already exist object
{
	this->length = strlen(new_str);
	delete[] str;
	this->str = new char[this->length + 1];

	for (size_t i = 0; i < this->length; i++)
	{
		this->str[i] = new_str[i];
	}

	this->str[length] = '\0';
}

size_t String::Length() const
{
	return length;
}

String String::operator*(const String& other)
{
	size_t count = 0;
	size_t this_length = strlen(this->str);
	size_t other_length = strlen(other.str);
	this_length > other_length ? length = this_length : length = other_length;

	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (this->str[i] == other.str[j])
			{
				count++;
			}
		}
	}
	String result;
	result.length = count + 1;
	result.str = new char[count + 1];
	size_t k = 0;
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (this->str[i] == other.str[j])
			{
				result.str[k] = this->str[i];
				k++;
				break;
			}
		}
	}
	result.str[count] = '\0';
	return result;
}

String String::operator/(const String& other)
{
	size_t count = 0;
	bool flag = false;
	size_t this_length = strlen(this->str);
	size_t other_length = strlen(other.str);
	this_length > other_length ? length = this_length : length = other_length;

	for (size_t i = 0; i < length; i++)
	{
		flag = false;
		for (size_t j = 0; j < length; j++)
		{
			if (this->str[i] == other.str[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			count++;
		}
	}
	String result;
	result.length = count + 1;
	result.str = new char[count + 1];
	size_t k = 0;
	for (size_t i = 0; i < length; i++)
	{
		flag = false;
		for (size_t j = 0; j < length; j++)
		{
			if (this->str[i] == other.str[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			result.str[k] = this->str[i];
			k++;
		}
	}
	result.str[count] = '\0';
	return result;
}

bool String::operator>(const String& other) const
{
	if (strcmp(this->str, other.str) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator<(const String& other) const
{
	if (strcmp(this->str, other.str) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator>=(const String& other) const
{
	if (strcmp(this->str, other.str) > 0 || strcmp(this->str, other.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator<=(const String& other) const
{
	if (strcmp(this->str, other.str) < 0 || strcmp(this->str, other.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator==(const String& other) const
{
	if (strcmp(this->str, other.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator!=(const String& other) const
{
	if (strcmp(this->str, other.str) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

String String::operator!() const
{
	String new_str;
	new_str.length = this->length;

	for (size_t i = 0; i < length; i++)
	{
		new_str.str[i] = this->str[length - 1 - i];
	}

	return new_str;
}

char& String::operator[](size_t index)
{
	if (index < this->length)
		return str[index];

		cerr << "The index is wrong: " << index << std::endl;
		exit(1);
}

char String::operator[](size_t index) const
{
	if (index < this->length)
		return str[index];

	cerr << "The index is wrong: " << index << std::endl;
	exit(1);
}

String String::operator()(size_t start_index, size_t str_length) const
{
	String new_str;
	str_length <= 0 || str_length > strlen(this->str) ? str_length = strlen(this->str) : str_length;
	new_str.length = str_length + 1;

	for (size_t i = 0; i < str_length; i++)
	{
		new_str.str[i] = this->str[start_index + i];
	}
	new_str[str_length] = '\0';
	return new_str;
}

String::operator int() const                   
{
	/*int sum = 0;												// return sum of all symbols in str
	
	for (size_t i = 0; i < length; i++)
	{
		sum += str[i];
	}

	return sum;*/

	return atoi(str);											// return digit from str (if there are digits only, if str has other symbols, return 0)
}

String::~String()
{
	if (str != nullptr)
	{
		delete[] this->str;
	}
	
	
}

//-----------------------------------------------------    Global methods   ---------------------------------

void operator<<(ostream& out, String& obj)
{
	for (size_t i = 0; i < obj.Length(); i++)
	{
		cout << obj[i];
	}
}

String &operator>>(std::istream& in, String& obj)           // cin >> --- doesn't read a space
{
	char str[250]{};
	cin >> str;
	obj.input_str(str);
	
	return obj;
}

