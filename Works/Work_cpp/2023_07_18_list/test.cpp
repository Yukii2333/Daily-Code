#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"
#include<list>

using namespace std;

int main()
{
	L::list<int> ls(6,0);
	L::list<int>::iterator it = ls.begin();
	//std::list<int> ls(6, 0);
	//std::list<int>::iterator it = ls.begin();
	int i = 0;
	while (it != ls.end())
	{
		*it = i++;
		++it;
	}
	it = ls.begin();
	while (it != ls.end())
	{
		if (*it == 3)
		{
			it = ls.erase(it);
			it = ls.insert(it, 999);
		}
		else
			++it;
	}
	for (auto It : ls)
	{
		cout << It << " ";
	}
	return 0;
}