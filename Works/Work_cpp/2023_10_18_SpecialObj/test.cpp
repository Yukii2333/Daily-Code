#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include"obj.hpp"

void test1()
{
	HeapOnly* hp = HeapOnly::Create();
	/*HeapOnly tmp(*hp);*/
	delete hp;
}

void test2()
{
	StackOnly st = StackOnly::Create();
	//StackOnly* tmp1 = new StackOnly();
	//static StackOnly tmp2();
}

//BanCopy Copy()
//{
//	BanCopy tmp;
//	return tmp;
//}

void test3()
{
	BanCopy bc1;
	//BanCopy bc2 = bc1;
	//BanCopy bc3(bc1);
	//Copy();
}

void test4()
{
	cout << &hungry::singleton::Create() << endl;
	cout << &hungry::singleton::Create() << endl;
	cout << &hungry::singleton::Create() << endl;
	cout << &hungry::singleton::Create() << endl;
	cout << &hungry::singleton::Create() << endl;
}

void test5()
{
	cout << lazy::singleton::Create() << endl;
	cout << lazy::singleton::Create() << endl;
	cout << lazy::singleton::Create() << endl;
	cout << lazy::singleton::Create() << endl;
	cout << lazy::singleton::Create() << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	test5();
	return 0;
}