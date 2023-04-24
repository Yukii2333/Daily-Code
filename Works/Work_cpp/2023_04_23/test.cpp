#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class A
{
public:
	void Print()
	{
		cout << a_<< endl;
	}
private:
	int a_;
};

int main()
{
	A* p = nullptr;
	p->Print();
	return 0;
}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		cout << this << endl;
//		year_ = year;
//		month_ = month;
//		day_ = day;
//	}
//	void Print()
//	{
//		cout << year_ << "-" << month_ << "-" << day_ << endl;
//	}
//private:
//	int year_;
//	int month_;
//	int day_;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 1, 1);
//	cout << &d1 << endl;
//	d1.Print();
//	return 0;
//}

//class Person
//{
//public:
//	int age_;
//};
//
//int main()
//{
//	Person a;
//	Person b;
//	Person c;
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year)
//	{
//		year_ = year;
//	}
//private:
//	int year_;
//};
//
//int main()
//{
//	Date a;
//	return 0;
//}

//class stu
//{
//public:
//	void who();
//private:
//	//分别是名字、性别、年龄
//	char* name_;
//	char* sex_;
//	int age_;
//};
//
//void  stu::who()
//{
//	cout << name_ << "-" << sex_ << "-" << age_ << endl;
//}