#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class Base1 
{
public:
	virtual void func1() 
	{ 
		cout << "Base1::func1" << endl; 
	}
	virtual void func2() 
	{ 
		cout << "Base1::func2" << endl;
	}
private:
	int b1 = 0;
};
class Base2 
{
public:
	virtual void func1() 
	{ 
		cout << "Base2::func1" << endl;
	}
	virtual void func2() 
	{
		cout << "Base2::func2" << endl; 
	}
private:
	int b2 = 0;
};

class Derive : public Base1, public Base2 
{
public:
	virtual void func1() 
	{ 
		cout << "Derive::func1" << endl; 
	}
	virtual void func3() 
	{ 
		cout << "Derive::func3" << endl; 
	}
private:
	int d1 = 0;
};

void test()
{
	Derive d;
}

int main()
{
	test();
	return 0;
}


//class Base 
//{
//public:
//	virtual void func1() 
//	{ 
//		cout << "Base::func1" << endl;
//	}
//	virtual void func2() 
//	{ 
//		cout << "Base::func2" << endl; 
//	}
//private:
//	int a = 0;
//};
//
//class Derive : public Base 
//{
//public:
//	virtual void func1() 
//	{
//		cout << "Derive::func1" << endl; 
//	}
//	virtual void func3() 
//	{ 
//		cout << "Derive::func3" << endl; 
//	}
//	virtual void func4() 
//	{ 
//		cout << "Derive::func4" << endl; 
//	}
//private:
//	int b = 0;
//};
//
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
//	cout << " ����ַ>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//
//void test()
//{
//	Base b;
//	Derive d;
//
//	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
//	PrintVTable(vTableb);
//	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTabled);
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//class Person 
//{
//public:
//	virtual void BuyTicket() 
//	{ 
//		cout << "��Ʊ-ȫ��" << endl; 
//	}
//};
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() 
//	{
//		cout << "��Ʊ-���" << endl; 
//	}
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}


//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	Base b;
//	cout << sizeof(b) << endl;
//}







//
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "����ȫ��" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "ѧ�����" << endl;
//	}
//};
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};
//
//
//void func(Person& people)
//{
//	people.BuyTicket();
//}
//
//void test()
//{
//	Car c;
//
//	Person Mike;
//	func(Mike);
//
//	Student Jonny;
//	func(Jonny);
//}
//
//int main()
//{
//	test();
//	return 0;
//}