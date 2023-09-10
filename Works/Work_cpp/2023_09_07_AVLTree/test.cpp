#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

#include"AVLTree.h"

int main()
{
	AVLTree<int, int> t;
	for (int i = 0; i < 1000; ++i)
	{
		t.Insert(make_pair(rand(), i));
		t.IsBalance();
	}
	cout << t.IsBalance() << endl;
	return 0;
}