#define _CRT_SECURE_NO_WARNINGS 1

#include "SLT.h"

void SLTDestroy(SLTNode** pplist)
{
	assert(*pplist != NULL);
	SLTNode* tail = *pplist;
	if (tail->next != NULL)
	{
		SLTNode* next_tail = tail->next;
		while (next_tail->next != NULL)
		{
			free(tail);
			tail = next_tail;
			next_tail = tail->next;
		}
		free(next_tail);
		tail = NULL;
		next_tail = NULL;
	}
	else
	{
		free(tail);
		tail = NULL;
	}
	printf("Destroyed\n");
}

SLTNode* SLTFind(SLTNode* plist, SLTDateType x)//²éÕÒ
{
	assert(plist != NULL);
	SLTNode* cur = plist;
	while (cur->next != NULL)
	{
		if (cur->data == x)
		{
			printf("Found it\n");
			return cur;
		}
		cur = cur->next;
	}
	printf("Not found\n");
	return NULL;
}

void SLTPopfront(SLTNode** pplist)//Í·É¾
{
	assert(*pplist != NULL);
	SLTNode* tail = *pplist;
	*pplist = tail->next;
	free(tail);
	tail = NULL;
}

void SLTPushFront(SLTNode** pplist, SLTDateType x)//Í·²å
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SLTPopBack(SLTNode** pplist)//Î²É¾
{
	assert(*pplist != NULL);
	SLTNode* tail = *pplist;
	if(tail != NULL)
	{
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		SLTNode* bf_tail = tail;
		tail = tail->next;
		bf_tail->next = NULL;
	}
	free(tail);
	tail = NULL;
}

SLTNode* BuySListNode(SLTDateType x)//ÉêÇë½Úµã
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail::");
		return;
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
		return newnode;
	}
}

void SLTPrint(SLTNode* phead)//´òÓ¡
{
	SLTNode* cur = phead;
	if(cur != NULL)
	{
		while (cur->next != NULL)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
		printf("%d->", cur->data);
	}
	printf("NULL\n");
}

void SLTPushBack(SLTNode** pplist, SLTDateType x)//Î²²å
{
	SLTNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	newnode = NULL;
}