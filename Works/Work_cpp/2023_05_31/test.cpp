#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

int main()
{
	string s("Hello World!");
	int pos = s.find_first_of(" ");
	cout << pos << endl;
	return 0;
}