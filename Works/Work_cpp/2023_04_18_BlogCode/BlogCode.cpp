#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>

using namespace std;

typedef struct SList
{
	int a[100];
	int size;
	int& Get(int pos)
	{
		assert(pos >= 0 && pos <= 100);
		return a[pos];
	}
}ST;


int main()
{
	ST s;
	s.a[0] = 0;
	int a = s.Get(0);
	cout << a << endl;
	s.Get(0) = 1;
	cout << "a[pos]:" << s.Get(0) << endl;
	return 0;
}

//typedef struct SList
//{
//	int a[100];
//	int size;
//}ST;
//
//int& Get(int pos,ST& ps)
//{
//	return ps.a[pos];
//}
//
//int main()
//{
//	ST s;
//	s.a[0] = 0;
//	int a = Get(0, s);
//	cout << a << endl;
//	Get(0, s) = 1;
//	cout <<"a[pos]:" << Get(0, s) << endl;
//	return 0;
//}

//using namespace std;
//
//int& Add(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << "Add:" << ret << endl;
//	return 0;
//}

//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << a << " " << b << endl;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int& b = a;
//	int& c = a;
//	return 0;
//}

//void Add(int a, double b)
//{
//	cout << "Add:" << a + b << endl;
//}
//
//void Add(double a, int b)
//{
//	cout << "Add:" << a + b << endl;
//}
//
//int main()
//{
//	Add(1, 1.1);
//	Add(1.1, 1);
//	return 0;
//}

//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Add(int a, int b, int c)
//{
//	return a + b + c;
//}
//
//int main()
//{
//	cout << "Add_two:" << Add(1, 2) << endl;
//	cout << "Add_three:" << Add(1, 2, 3) << endl;
//	return 0;
//}

//int Add(int a, int b)
//{
//	return a + b;
//}
//
//double Add(double a, double b)
//{
//	return a + b;
//}
//
//int main()
//{
//	cout << "Add_int:" << Add(1, 2) << endl;
//	cout << "Add_double:" << Add(1.1, 2.2) << endl;
//	return 0;
//}