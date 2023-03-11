#define _CRT_SECURE_NO_WARNINGS 1

#include"LTData.h"

void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* tail = pHead->_next;
	while (tail != pHead)
	{
		ListNode* next = tail->_next;
		free(tail);
		tail = next;
	}
	pHead->_prev = pHead;
	pHead->_next = pHead;
	printf("Destoryed!\n");
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL && pHead->_next != NULL);
	ListNode* pos = pHead->_next;
	while (pos != pHead)
	{
		if (pos->_data == x)
		{
			printf("Found!\n");
			return pos;
		}
		pos = pos->_next;
	}
	printf("Not found!\n");
	return NULL;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_prev);
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_next);
}

ListNode* BuyNweNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}

ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	head->_data = 0;
	head->_next = head;
	head->_prev = head;
	return head;
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->_next, x);
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyNweNode(x);
	newnode->_prev = pos->_prev;
	newnode->_next = pos;
	pos->_prev->_next = newnode;
	pos->_prev = newnode;
}

void ListPrint(ListNode* pHead)
{
	if (pHead->_next != NULL)
	{
		ListNode* tail = pHead->_next;
		while (tail != pHead)
		{
			printf("%d<=>", tail->_data);
			tail = tail->_next;
		}
		printf("\n");
	}
}