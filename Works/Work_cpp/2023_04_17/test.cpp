#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>

struct List
{
	int a[100];
	int size;
	int& Get(int pos)
	{
		assert(pos>=0 && pos<100);
		return a[pos];
	}
};

int main()
{
	List s;
	s.Get(0) = 1;
	std::cout << s.Get(0) << std::endl;
	s.Get(0)++;
	std::cout << s.Get(0) << std::endl;
	return 0;
}