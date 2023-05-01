#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

void test()
{
	Date d1(2022,12,1);
	Date d2(d1);
	Date d3;
	d3 = d2;
	d2 += 996;
	int day = d2 - d3;
	std::cout << "d1:";
	d1.Print();
	std::cout << "d2:";
	d2.Print();
	std::cout << "d3:";
	d3.Print();
	std::cout <<"d2-d3:"<< day << std::endl;
}

int main()
{
	test();
	return 0;
}