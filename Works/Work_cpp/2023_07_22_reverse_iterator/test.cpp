#define _CRT_SECURE_NO_WARNINGS 1

#include"Vector.h"
#include<vector>

using namespace std;

int main()
{
	V::vector<int> v(9);
	V::vector<int>::iterator it = v.begin();
	int i = 0;
	while (it != v.end())
	{
		*it = i++;
		it++;
	}
	V::vector<int>::reverse_iterator iit = v.rbegin();
	while (iit != v.rend())
	{
		cout << *iit << " ";
		++iit;
	}
	vector<int> t(9);
	return 0;
}