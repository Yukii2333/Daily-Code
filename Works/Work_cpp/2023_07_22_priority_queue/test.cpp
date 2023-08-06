#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"Priority_queeu.h"

using namespace std;

int main()
{
	vector<int> v;
	for (size_t i = 0; i < 9; ++i)
	{
		v.push_back(i);
	}
	PQ::priority_queue<int,vector<int>,less<int>> pq(v.begin(),v.end());
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}