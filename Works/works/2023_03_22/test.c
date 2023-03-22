#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapInit(HP* hp)
{
	HPDataType* tmp = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	hp->a = tmp;
	hp->capacity = 4;
	hp->size = 0;
}

bool HeapEmpty(HP* hp)
{
	assert(hp);
	return hp->size == 0;
}

void HeapExchange(HPDataType* hp1, HPDataType* hp2)
{
	HPDataType tmp = *hp1;
	*hp1 = *hp2;
	*hp2 = tmp;
}

//向上调整
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			HeapExchange(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//小堆，大堆调整即可
void HeapPush(HP* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(hp->a,sizeof(HPDataType) * hp->capacity*2);
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}
		hp->a = tmp;
		hp->capacity *= 2;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size-1);
}

//向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child+1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			HeapExchange(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	HeapExchange(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}

HPDataType HeapTop(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->a[0];
}

int HeapSize(HP* hp)
{
	assert(hp);
	return hp->size;
}

void HeapDestory(HP* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
}