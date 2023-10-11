#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"SmartStr.h"

using namespace std;

class A
{
public:
	A(){ cout << "A::A()" << endl; }
	~A() { cout << "A::~A()" << endl; }
	int get() { return a_; }
private:
	int a_ = 0;
};

class Node
{
public:
	Node() { cout << "Node::Node()" << endl; }
	~Node() { cout << "Node::~Node()" << endl; }
	
	MySTL::weak_ptr<Node> prev_ = nullptr;
	MySTL::weak_ptr<Node> next_ = nullptr;
};

void test1()
{
	//A a;
	auto_ptr<A> a1(new A);
	auto_ptr<A> a2(new A);
	//MySTL::auto_ptr<A> a3;
	auto_ptr<A> a3(a2);
	int a = 1;
}

void test2()
{
	unique_ptr<A> u1(new A);
	//unique_ptr<A> u2(u1);
}

void test3()
{
	//MySTL::shared_ptr<A>s1(new A);
	//MySTL::shared_ptr<A>s2(s1);
	//MySTL::shared_ptr<A>s3(new A);
	//MySTL::shared_ptr<A>s4(s3);
	//s4 = s2;
	MySTL::shared_ptr<Node> n1(new Node);
	MySTL::shared_ptr<Node> n2(new Node);
	n1->next_ = n2;
	n2->prev_ = n1;
}

int main()
{
	test3();
	return 0;
}