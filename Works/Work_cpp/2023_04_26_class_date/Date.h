#pragma once

#include<iostream>

class Date
{
public:
	//全缺省构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
	Date& operator=(const Date& d);

	//拷贝构造函数
	Date(const Date& d);

	//析构函数
	~Date()
	{

	}

	//获取某月天数
	int GetMonthDay(int year, int month);

	//日期+=天数
	Date& operator+=(int day);

	//日期+天数
	Date operator+(int day);

	//日期-=天数
	Date& operator-=(int day);

	//日期-天数
	Date operator-(int day);

	//前置++
	Date& operator++();

	//后置++
	Date operator++(int);

	//前置--
	Date& operator--();

	//后置--
	Date operator--(int);

	void Print()
	{
		std::cout << year_ << "-" << month_ << "-" << day_ << std::endl;
	}
private:
	int year_;
	int month_;
	int day_;
};