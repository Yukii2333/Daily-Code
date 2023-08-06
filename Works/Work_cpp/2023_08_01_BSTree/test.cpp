#define _CRT_SECURE_NO_WARNINGS 1

#include"BSTree.h"
using namespace std;

int main()
{
	BSTree<int, int> t;
	t.Insert(3, 1);
	t.Insert(5, 5);
	t.Insert(6, 6);
	t.Insert(7, 7);
	t.Insert(2, 2);
	t.Insert(1, 9);
	BSTreeNode<int, int>* tmp = t.Find(1);
	cout << tmp->_val << endl;
	t.InOrder();
	t.Erase(3);
	cout << endl;
	t.InOrder();
	return 0;
}
