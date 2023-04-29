#pragma once

#include<iostream>

class Date
{
public:
	Date(int year = 0,int month = 0, int day = 0)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
	Date& operator=(const Date& d)
	{
		year_ = d.year_;
		month_ = d.month_;
		day_ = d.day_;
		return (*this);
	}
	void Print()
	{
		std::cout << year_ << "-" << day_ << "-" << day_ << std::endl;
	}
private:
	int year_;
	int month_;
	int day_;
};