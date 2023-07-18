#define _CRT_SECURE_NO_WARNINGS 1

#include"Vector.h"
#include<vector>

using namespace std;

int main()
{
	V::vector<int> t;
	t.push_back(9);
	t.resize(10, 7);
	V::vector<int> t2 = t;
	//t2 = t;
	t2.pop_back(4);
	V::vector<int>::iterator it = t2.begin();
	while (*it != 9)
	{
		++it;
	}
	it=t2.insert(it, 0);
	it=t2.insert(it, 1);
	it=t2.insert(it, 2);
	it=t2.insert(it, 3);
	for (auto T : t2)
	{
		cout << T << " ";
	}
	cout << endl;
	t2.erase(it+1);
	for (auto T : t2)
	{
		cout << T << " ";
	}
	return 0;
}