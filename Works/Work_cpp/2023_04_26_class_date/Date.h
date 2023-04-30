#pragma once

#include<iostream>

class Date
{
public:
	//ȫȱʡ���캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
	Date& operator=(const Date& d);

	//�������캯��
	Date(const Date& d);

	//��������
	~Date()
	{

	}

	//��ȡĳ������
	int GetMonthDay(int year, int month);

	//����+=����
	Date& operator+=(int day);

	//����+����
	Date operator+(int day);

	//����-=����
	Date& operator-=(int day);

	//����-����
	Date operator-(int day);

	//ǰ��++
	Date& operator++();

	//����++
	Date operator++(int);

	//ǰ��--
	Date& operator--();

	//����--
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