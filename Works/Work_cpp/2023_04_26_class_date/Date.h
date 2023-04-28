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
	void Print()
	{
		std::cout << year_ << "-" << day_ << "-" << day_ << std::endl;
	}
private:
	int year_;
	int month_;
	int day_;
};