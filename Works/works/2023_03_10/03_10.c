#define _CRT_SECURE_NO_WARNINGS 1

#include"LTData.h"

void test()
{
	ListNode* head = ListCreate();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);
	ListPushFront(head,0);
	ListPopFront(head);
	ListNode* ret = ListFind(head, 3);
	ListInsert(ret, 9);
	ListInsert(ret, 10);
	ListErase(ret);
	ListPopBack(head);
	ListPopBack(head);
	ListPrint(head);
	ListDestory(head);
}

int main()
{
	test();
	return 0;
}