#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class Date
{
public:
	void Init(int year, int month, int day)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
	void Print()
	{
		cout << year_ << "-" << month_ << "-" << day_ << endl;
	}
private:
	int year_;
	int month_;
	int day_;
};

int main()
{
	Date d1;
	d1.Init(2022, 12, 1);
	d1.Print();

	Date d2;
	d2.Init(2022, 12, 2);
	d2.Print();
	return 0;
}