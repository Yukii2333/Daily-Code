#include"HuffumanTree.h"


void test()
{
	HFTree<char> h1;
	char ptr1[] = "abcdefg";
	int ptr2[] = { 5,2,4,1,7,6,9 };
	//创建函数的接口是Create(信息数组,对应权重数组,对应大小)
	h1.CreateTree(ptr1, ptr2, 7);
	cout <<"WPL:" << h1.GetWPL() << endl;
	h1.Preorder();
	cout << endl;
	h1.HuffumanCode();
	h1.Destroy();
}

int main()
{
	test();

	return 0;
}
