#define _CRT_SECURE_NO_WARNINGS 1

using namespace std;
#include"RBTRee.h"
#include<iostream>
#include<vector>



//int main()
//{
//	RBTree<int, int> rb;
//	for (int i = 0; i < 10; ++i)
//	{
//		rb.Insert(make_pair(rand(), i));
//	}
//	cout << rb.IsRBTree() << endl;
//	return 0;
//}

int main()
{
	const int N = 10000000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	RBTree<int, int> rbt;
	for (auto e : v)
	{
		rbt.Insert(make_pair(e, e));
	}
	cout << rbt.IsBalance() << endl;


	return 0;
}