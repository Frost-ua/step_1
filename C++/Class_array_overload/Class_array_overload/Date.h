#pragma once

class Date
{
public:
	Date(const size_t& day, const size_t& month, const size_t& year);
	Date() = default;
	void setDay(const size_t& day);
	void setMonth(const size_t& month);
	void setYear(const size_t& year);
	size_t getDay()const { return day; };
	size_t getMonth()const { return month; };
	size_t getYear()const { return year; };
private:
	size_t day = MIN_DAY;
	size_t month = MIN_MONTH;
	size_t year = CURRENT_YEAR;
	static const size_t MIN_DAY = 1, MAX_DAY = 31, MIN_MONTH = 1, MAX_MONTH = 12, CURRENT_YEAR = 2021;
};

inline Date::Date(const size_t& day, const size_t& month, const size_t& year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

inline void Date::setDay(const size_t& day)
{
	day >= MIN_DAY && day <= MAX_DAY ? this->day = day : this->day = MIN_DAY;
}

inline void Date::setMonth(const size_t& month)
{
	month >= MIN_MONTH && month <= MAX_MONTH ? this->month = month : this->month = MIN_MONTH;
}

inline void Date::setYear(const size_t& year)
{
	year >= CURRENT_YEAR ? this->year = year : this->year = CURRENT_YEAR;
}



