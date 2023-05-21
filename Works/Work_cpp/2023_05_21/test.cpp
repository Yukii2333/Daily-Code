#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

template<class T>
class A
{
public:
	//...
private:
	T info_;
};

int main()
{
	A<int> num;
	A<char> name;
	return 0;
}

//int Add(int a, int b)
//{
//	return a + b;
//}
//
//template<typename T>
//T Add(T a, T b)
//{
//	return a + b;
//}
//
//int main()
//{
//	Add(1, 2);
//	Add<int>(1, 2);
//
//	Add(1, 1.1);
//	Add(1.1, 2.2);
//	return 0;
//}