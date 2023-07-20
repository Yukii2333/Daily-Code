#define _CRT_SECURE_NO_WARNINGS 1

#include<stack>
#include<queue>
#include"Queue.h"
#include"Stack.h"

using namespace std;

int main()
{
	QUE::queue<int> q;
	for (size_t i = 0; i < 9; ++i)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}

//int main()
//{
//	ST::stack<int> st;
//	for (size_t i = 0; i < 9; ++i)
//	{
//		st.push(i);
//	}
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	return 0;
//}