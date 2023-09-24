#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"BloomFilter.h"

using namespace std;

int main()
{
	MyStd::BloomFilter<100000> bf;
	bf.set("С��");
	bf.set("Сè");
	bf.set("С��");
	bf.set("С��");
	cout << bf.test("С��") << endl;
	cout << bf.test("С��1") << endl;
	cout << bf.test("С1��") << endl;
	cout << bf.test("1С��") << endl;
	return 0;
}