#pragma once

#include<iostream>
#include<assert.h>

class Date
{
	//��Ԫ��������
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
	friend std::istream& operator>>(std::istream& in, Date& d);
public:
	//ȫȱʡ���캯��
	Date(int year = 1900, int month = 1, int day = 1);

	Date& operator=(const Date& d);

	//�������캯��
	Date(const Date& d);

	//����������ȫ���������ͣ����������Զ����٣����Բ���д
	~Date()
	{

	}

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

	//����>
	bool operator>(const Date& d);

	//����==
	bool operator==(const Date& d);

	//���ڵ���>=
	bool operator>=(const Date& d);

	//С��<
	bool operator<(const Date& d);

	//С�ڵ���<=
	bool operator<=(const Date& d);

	//������!=
	bool operator!=(const Date& d);

	// ����-���� ��������
	int operator-(const Date& d);

	//��ȡ������������ڵ�������
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

//��������ȡ
std::ostream& operator<<(std::ostream& out, const Date& d);

//����������
std::istream& operator>>(std::istream& in, Date& d);

//��ȡĳ������
int GetMonthDay(const int year, const int month);