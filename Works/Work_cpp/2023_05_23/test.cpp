#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str("abcdefg");
	string::iterator it1 = str.begin();

	string::reverse_iterator it2 = str.rbegin();

	return 0;
}