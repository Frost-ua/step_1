#pragma once
class fraction
{
public:
	fraction(int numer, int denom);
	fraction(int numer);
	fraction();
	int get_numer() const;
	int get_denomr() const;
	void set_numer(int numer);
	void set_denom(int denom);
	void print_fraction() const;
	fraction &fraction_reduction();
	
	fraction operator + (const fraction& other) const;
	fraction operator + (int value) const;
	fraction operator - (const fraction& other) const;
	fraction operator * (const fraction& other) const;
	fraction operator * (int value) const;
	fraction operator / (const fraction& other) const;
	fraction operator ++ ();
	fraction operator ++ (int);
	fraction operator -- ();
	fraction operator -- (int);
	bool operator == (const fraction& other) const;
	bool operator != (const fraction& other) const;
	bool operator > (const fraction& other) const;
	bool operator < (const fraction& other) const;
	bool operator += (int value) const;
	bool operator *= (int value) const;

private:
	int numer;
	int denom;
};

