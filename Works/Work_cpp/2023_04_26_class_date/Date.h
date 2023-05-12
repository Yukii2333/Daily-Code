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
	Date operator+(int day) const;

	//����-=����
	Date& operator-=(int day);

	//����-����
	Date operator-(int day) const;

	//ǰ��++
	Date& operator++();

	//����++
	Date operator++(int);

	//ǰ��--
	Date& operator--();

	//����--
	Date operator--(int);

	//����>
	bool operator>(const Date& d) const;

	//����==
	bool operator==(const Date& d) const;

	//���ڵ���>=
	bool operator>=(const Date& d) const;

	//С��<
	bool operator<(const Date& d) const;

	//С�ڵ���<=
	bool operator<=(const Date& d) const;

	//������!=
	bool operator!=(const Date& d) const;

	// ����-���� ��������
	int operator-(const Date& d) const;

	Date* operator&();
	const Date* operator&() const;


	//��ȡ������������ڵ�������
	int GetMonthDay_sum(const Date& d) const;


	void Print() const
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