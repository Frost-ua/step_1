#pragma once

class String
{
public:
	String(const char* str);
	String(size_t _length);
	String();
	String(const String& other);
	String(String&& other);
	String& operator = (const String& other);
	String operator + (const String& other) const;									 // obj + obj
	void output_str() const;
	void input_str(const char* new_str);
	size_t Length() const;
	//------------------------------------------------------------------------------------------------------------------
	String operator + (const char* str) const;										 // obj + "text"
	static String str_concat(const char* str, const String& other);                 // "text" + obj
	String &operator ++ ();
	String operator ++ (int);
	String operator * (const String& other);
	String operator / (const String& other);
	bool operator > (const String& other) const;
	bool operator < (const String& other) const;
	bool operator >= (const String& other) const;
	bool operator <= (const String& other) const;
	bool operator == (const String& other) const;
	bool operator != (const String& other) const;
	String operator ! () const;
	char& operator [] (size_t index);
	char operator [] (size_t index) const;
	String operator ()(size_t start_index, size_t str_length = 0) const;
	explicit operator int() const;
	~String();
private:
	char* str;
	size_t length;
};

void operator << (std::ostream& out, String& obj);
String &operator >> (std::istream& out, String& obj);
