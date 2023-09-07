#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

#include"AVLTree.h"

int main()
{
	AVLTree<int, int> t;
	pair<int, int> p(1,1);
	t.Insert(p);
	t.Insert(make_pair(0, 0));
	t.Insert(make_pair(4, 4));
	t.Insert(make_pair(3, 3));
	t.Insert(make_pair(5, 5));
	t.Insert(make_pair(2, 2));
	return 0;
}