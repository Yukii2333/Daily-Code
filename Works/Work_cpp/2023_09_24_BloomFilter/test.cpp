#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"BloomFilter.h"

using namespace std;

int main()
{
	MyStd::BloomFilter<100000> bf;
	bf.set("小狗");
	bf.set("小猫");
	bf.set("小猪");
	bf.set("小羊");
	cout << bf.test("小猪") << endl;
	cout << bf.test("小猪1") << endl;
	cout << bf.test("小1猪") << endl;
	cout << bf.test("1小猪") << endl;
	return 0;
}