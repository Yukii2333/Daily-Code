#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void test()
{
	HP heap;
	HeapInit(&heap);
	HeapPush(&heap, 5);
	HeapPush(&heap, 6);
	HeapPush(&heap, 2);
	HeapPush(&heap, 1);
	HeapPush(&heap, 13);
	HeapPush(&heap, 0);
	printf("%d\n", HeapSize(&heap));
	printf("%d ", HeapTop(&heap));
	HeapPop(&heap);
	printf("%d ", HeapTop(&heap));
	HeapPop(&heap);
	printf("%d ", HeapTop(&heap));
	HeapPop(&heap);
	printf("%d ", HeapTop(&heap));
	HeapPop(&heap);
	printf("%d ", HeapTop(&heap));
	HeapPop(&heap);
	printf("%d ", HeapTop(&heap));
	HeapPop(&heap);
	HeapDestory(&heap);
}

int main()
{
	test();
	return 0;
}