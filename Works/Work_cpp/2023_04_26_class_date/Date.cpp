#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

Date::Date(int year, int month, int day)
{
	if ((month > 12 || month < 1) || (day < 1 || day > GetMonthDay(year, month)))
	{
		std::cout << "输入有误！" << std::endl;
		assert(false);
	}
	year_ = year;
	month_ = month;
	day_ = day;
}

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

int GetMonthDay(const int year, const int month)
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
	if (day < 0)
	{
		return *this -= (-1 * day);
	}
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
	if (day < 0)
	{
		return *this += (- 1 * day);
	}
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

bool Date::operator>(const Date& d)
{
	if (year_ < d.year_)
		return false;
	else if (year_ > d.year_)
		return true;
	else
	{
		if (month_ < d.month_)
			return false;
		else if (month_ > d.month_)
			return true;
		else
		{
			if (day_ > d.day_)
				return true;
			else
				return false;
		}
	}
}

bool Date::operator==(const Date& d)
{
	return year_ == d.year_ && 
			day_ == d.day_ &&
			month_ == d.month_;
}

bool Date::operator>=(const Date& d)
{
	return (*this == d) || (*this > d);
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

int Date::GetMonthDay_sum(const Date& d)
{
	int arr[13] = { 0,0,31,59,90,120,151,181,212,243,273,304,334 };
	if ((d.month_ > 2) && ((d.year_ % 100 != 0 && d.year_ % 4 == 0) || (d.year_ % 400 == 0)))
	{
		return arr[d.month_] + 1 + d.day_;
	}
	return arr[d.month_] + d.day_;
}

int Date::operator-(const Date& d)
{
	if (year_ == d.year_)
	{
		return GetMonthDay_sum(*this) - GetMonthDay_sum(d);
	}
	int difr_y = abs(year_ - d.year_);
	Date tmp = d;
	if (year_ > d.year_)
	{
		tmp = *this;
	}
	int difr_d = 0;
	while (difr_y--)
	{
		int day = GetMonthDay_sum(tmp);
		tmp -= day;
		difr_d += day;
	}
	difr_d += GetMonthDay_sum(tmp);
	if(year_ > d.year_)
		return difr_d - GetMonthDay_sum(d);
	else 
		return GetMonthDay_sum(*this) - difr_d;
}

std::ostream& operator<<(std::ostream& out, const Date& d)
{
	out << d.year_ << "年" << d.month_ << "月" << d.day_ << "日";
	return out;
}

std::istream& operator>>(std::istream& in, Date& d)
{
	in >> d.year_ >> d.month_ >> d.day_;
	if ((d.month_ > 12 || d.month_ < 1) || (d.day_ < 1 || d.day_ > GetMonthDay(d.year_, d.month_)))
	{
		std::cout << "输入有误！" << std::endl;
		assert(false);
	}
	return in;
}