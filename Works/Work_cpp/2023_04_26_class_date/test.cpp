#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

void test()
{
	Date d1(2022,12,1);
	Date d2(d1);
	Date d3;
	d3 = d2;
	d2++;
	++d3;
	d2--;
	--d3;
	d1.Print();
	d2.Print();
	d3.Print();
}

int main()
{
	test();
	return 0;
}