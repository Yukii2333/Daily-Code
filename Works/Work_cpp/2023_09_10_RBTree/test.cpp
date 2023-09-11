#define _CRT_SECURE_NO_WARNINGS 1

#include"RBTRee.h"
#include<iostream>

using namespace std;

int main()
{
	RBTree<int, int> rb;
	for (int i = 0; i < 5000; ++i)
	{
		rb.Insert(make_pair(rand(), i));
	}
	cout << rb.IsRBTree() << endl;
	return 0;
}