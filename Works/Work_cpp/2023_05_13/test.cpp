#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class A
{
public:
	void Print()
	{
		cout << a_ << endl;
	}
	static int& Add()
	{
		a_++;
		return a_;
	}
private:
	static int a_;
};

int A::a_ = 0;

int main()
{
	A a1;
	a1.Print();
	cout << a1.Add() << endl;
	return 0;
}