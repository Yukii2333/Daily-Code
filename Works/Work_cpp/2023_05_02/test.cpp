#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year = 2022, int month = 12, int day = 1)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
	Date& operator++()
	{
		day_ += 1;
		return *this;
	}
	Date operator++(int)
	{
		Date tmp = *this;
		day_ += 1;
		return tmp;
	}

private:
	int year_;
	int month_;
	int day_;
};

int main()
{
	Date d1(2023, 12, 1);
	

	return 0;
}

//class Date
//{
//public:
//	Date(int year = 2022, int month = 12, int day = 1)
//	{
//		year_ = year;
//		month_ = month;
//		day_ = day;
//	}
//	Date(const Date& d)
//	{
//		year_ = d.year_;
//		month_ = d.month_;
//		day_ = d.day_;
//	}
//
//	int year_;
//	int month_;
//	int day_;
//};
//
//Date& operator=(Date& d1,const Date& d2)
//{
//	d1.year_ = d2.year_;
//	d1.month_ = d2.month_;
//	d1.day_ = d2.day_;
//	return d1;
//}
//
//int main()
//{
//	Date d1(2023, 12, 1);
//	Date d2(d1);
//	Date d3;
//	Date d4;
//	d4 = d3 = d2;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 2022, int month = 12, int day = 1)
//	{
//		year_ = year;
//		month_ = month;
//		day_ = day;
//	}
//	Date(const Date& d)
//	{
//		year_ = d.year_;
//		month_ = d.month_;
//		day_ = d.day_;
//	}
//	Date& operator=(const Date& d)
//	{
//		year_ = d.year_;
//		month_ = d.month_;
//		day_ = d.day_;
//		return (*this);
//	}
//
//private:
//	int year_;
//	int month_;
//	int day_;
//};
//
//int main()
//{
//	Date d1(2023,12,1);
//	Date d2(d1);
//	Date d3;
//	Date d4;
//	d4 = d3 = d2;
//	return 0;
//}

//class stack
//{
//public:
//	stack(int capacity = 4)
//	{
//		a_ = (int*)malloc(sizeof(int) * capacity);
//		if (a_ == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//		capacity_ = capacity;
//		top_ = 0;
//	}
//
//	~stack()
//	{
//		free(a_);
//		a_ = nullptr;
//	}
//private:
//	int* a_;
//	int capacity_;
//	int top_;
//};

//class Date
//{
//public:
//	void Print()
//	{
//		cout << year_ << "-" << month_ << "-" << day_ << endl;
//	}
//private:
//	int year_ = 2022;
//	int month_ = 12;
//	int day_ = 1;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}