#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include"bitset.h"

int main()
{
	MyStd::bitset<10> bs;
	bs.set(10);
	bs.set(2);
	if (bs.test(2))
		cout << 2 << endl;
	return 0;
}