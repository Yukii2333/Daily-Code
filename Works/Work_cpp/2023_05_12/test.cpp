#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;


class Date
{
public:
	Date(int year, int month, int day)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}

private:
	int year_;
	int month_;
	int day_;
};

class A
{
public:
	A()
		:a_(0)
	{
		cout << "A()" << endl;
	}
private:
	int a_;
};

class B
{
public:
	B()
	{}

private:
	A ba_;
	int bb_;
};

int main()
{
	B b;
	return 0;
}