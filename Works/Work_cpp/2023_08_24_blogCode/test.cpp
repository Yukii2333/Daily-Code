#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//class Person
//{
//public:
//    void Print()
//    {
//        cout << "name:" << name_ << endl;
//        cout << "age" << age_ << endl;
//    }
//protected:
//    string name_ = "XiaoMing";
//    int age_ = 18;
//};
//
////继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分
//
//class Student : public Person
//{
//protected:
//    int stuid_;
//};
//
//class Teacher : public Person
//{
//protected:
//    int jobid_;
//};
//
//
//int main()
//{
//    Student st;
//    Person ps = st;
//    Person* pps = &st;
//    Person& pp = st;
//
//    st = ps;
//
//    pps = &ps;
//    Student* pst = (Student*)&ps;
//	return 0;
//}

//class A
//{
//public:
//	void func()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	void func()
//	{
//		cout << "B::func()" << endl;
//	}
//};
//
//void test()
//{
//	A a;
//	B b;
//	a.func();
//	b.func();
//	b.A::func();
//}
//
//int main()
//{
//	test();
//	return 0;
//}

class Person
{
public:
	Person()
	{
		++count_;
	}
protected:
	string name_;
public:
	static int count_;
};

int Person::count_ = 0;

class Student : public Person
{
protected:
	int stuid_;
};

void test()
{
	Person p1;
	Person p2;
	Student s1;
	Student s2;
	cout << "人数：" << Person::count_ << endl;
}

int main()
{
	test();
	return 0;
}

