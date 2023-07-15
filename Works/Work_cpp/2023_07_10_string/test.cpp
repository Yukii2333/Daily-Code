#define _CRT_SECURE_NO_WARNINGS 1

#include"_string.h"

using namespace std;

int main()
{
	Str::string a1;
	Str::string a2("Hello World!");
	Str::string a3(a2);
	const Str::string a4("114514");
	for (auto it : a2)
	{
		cout << it;
	}
	cout << endl;
	a2.insert(5,'w');
	for (auto it : a2)
	{
		cout << it;
	}
	cout << endl;
	a2.insert(6, " Linux");
	for (auto it : a2)
	{
		cout << it;
	}
	cout << endl;
	a2.erase(6, 6);
	for (auto it : a2)
	{
		cout << it;
	}
	cout << endl;
	return 0;
}