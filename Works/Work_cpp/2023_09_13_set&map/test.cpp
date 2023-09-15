#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<set>
#include"Set.h"
#include"Map.h"
using namespace std;

int main()
{
	MyStd::set<int> s;
	MyStd::map<int, int> m;
	for (int i = 0; i < 10; ++i)
	{
		s.Insert(i);
		m.Insert(make_pair(i,i));
	}
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : m)
	{
		cout << e.first << " "<<e.second<<"  ";
	}
	return 0;
}