#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

Date& Date::operator=(const Date& d)
{
	year_ = d.year_;
	month_ = d.month_;
	day_ = d.day_;
	return (*this);
}

Date::Date(const Date& d)
{
	year_ = d.year_;
	month_ = d.month_;
	day_ = d.day_;
}

int Date::GetMonthDay(int year, int month)
{
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((month == 2) && ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0)))
	{
		return arr[month] + 1;
	}
	return arr[month];
}

Date& Date::operator+=(int day)
{
	day_ += day;
	int tmp = GetMonthDay(year_, month_);
	while (day_ > tmp)
	{
		day_ -= tmp;
		++month_;
		if (month_ == 13)
		{
			++year_;
			month_ = 1;
		}
		tmp = GetMonthDay(year_, month_);
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	while (day>0)
	{
		if (day < day_)
		{
			day_ -= day;
			day = 0;
		}
		else
		{
			day -= day_;
			month_ -= 1;
			if (month_ == 0)
			{
				year_ -= 1;
				month_ = 12;
			}
			day_ = GetMonthDay(year_, month_);
		}
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	++* this;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	--* this;
	return tmp;
}