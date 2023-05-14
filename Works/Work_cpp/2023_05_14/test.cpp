#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class B
{
public:
	void Print(const A& a)
	{
		cout << "a_:" << a.a_ << endl;
		cout << "b_:" << b_ << endl;
	}
private:
	int b_;
};

class A
{
	friend class B;
public:


private:
	int a_;
};

int main()
{


	return 0;
}