#pragma once

#include<iostream>
#include<assert.h>

class Date
{
	//友元函数声名
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
	friend std::istream& operator>>(std::istream& in, Date& d);
public:
	//全缺省构造函数
	Date(int year = 1900, int month = 1, int day = 1);

	Date& operator=(const Date& d);

	//拷贝构造函数
	Date(const Date& d);

	//析构函数，全是内置类型，函数结束自动销毁，可以不用写
	~Date()
	{

	}

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

	//大于>
	bool operator>(const Date& d);

	//等于==
	bool operator==(const Date& d);

	//大于等于>=
	bool operator>=(const Date& d);

	//小于<
	bool operator<(const Date& d);

	//小于等于<=
	bool operator<=(const Date& d);

	//不等于!=
	bool operator!=(const Date& d);

	// 日期-日期 返回天数
	int operator-(const Date& d);

	//获取该年年初到日期的总天数
	int GetMonthDay_sum(const Date& d);

	void Print()
	{
		std::cout << year_ << "-" << month_ << "-" << day_ << std::endl;
	}
private:
	int year_;
	int month_;
	int day_;
};

//重载流提取
std::ostream& operator<<(std::ostream& out, const Date& d);

//重载流插入
std::istream& operator>>(std::istream& in, Date& d);

//获取某月天数
int GetMonthDay(const int year, const int month);