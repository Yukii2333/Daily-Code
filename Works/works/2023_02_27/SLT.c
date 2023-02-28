#define _CRT_SECURE_NO_WARNINGS 1

#include "SLT.h"

void test()
{
	SLTNode* s = NULL;
	SLTPushBack(&s, 1);
	SLTPopfront(&s);
	SLTPushBack(&s, 2);
	SLTPushBack(&s, 3);
	SLTPushBack(&s, 4);
	SLTPushFront(&s, 0);
	SLTPopBack(&s);
	SLTNode* ret1 = SLTFind(s, 2);
	SLTNode* ret2 = SLTFind(s, 1);
	SLTPrint(s);
	SLTDestroy(&s);
}

int main()
{
	test();
	return 0;
}