#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	int* tmp = (SLDateType*)malloc(sizeof(SLDateType)*INIT_NUM);
	if (tmp == NULL)
	{
		perror("SeqListInit::calloc");
		return;
	}
	ps->a = tmp;
	tmp = NULL;
	ps->size = 0;
	ps->capacity = INIT_NUM;
}

void SeqListDestroy(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListPrint(SeqList* ps)
{
 	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	if (ps->size == ps->capacity)
	{
		int* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("SeqListPushBack::realloc");
			return;
		}
		ps->a = tmp;
		tmp = NULL;
		ps->capacity *= 2;
	}
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SeqList* ps)
{
	if (ps->size > 0)
	{
		ps->size--;
	}
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	if (ps->size == ps->capacity)
	{
		int* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("SeqListPushFront::realloc");
			return;
		}
		ps->a = tmp;
		tmp = NULL;
		ps->capacity *= 2;
	}
	for (int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	for (int i = 0; i < ps->size - 2; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	int flag = 0;
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i + 1;
		}
	}
	printf("Not Found!\n");
	return 0;
}

void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	if (ps->size == ps->capacity)
	{
		int* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("SeqListInsert::realloc");
			return;
		}
		ps->a = tmp;
		tmp = NULL;
		ps->capacity *= 2;
	}
	for (int i = ps->size; i > pos - 1; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos - 1] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, int pos)
{
	for (int i = pos - 1; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void test()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushFront(&s, 1);
	SeqListPopFront(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	int ret = SeqListFind(&s, 2);
	SeqListInsert(&s, 2, 3);
	SeqListErase(&s, 2);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListDestroy(&s);
}

int main()
{
	test();
	return 0;
}