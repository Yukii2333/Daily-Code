#include"CircularSingleList.h"

void test()
{
	CSLTNode Guard;
	CSListInit(&Guard);
	CSListPushFront(&Guard, 1);
	CSListPushFront(&Guard, 2);
	CSListPushFront(&Guard, 3);
	CSListPushFront(&Guard, 4);
	CSListPushFront(&Guard, 5);
	CSListPopFront(&Guard);
	CSListPopFront(&Guard);
	CSListPushBack(&Guard, 0);
	CSListPushBack(&Guard, 1);
	CSListPushBack(&Guard, 2);
	CSListPushBack(&Guard, 3);
	CSListPopBack(&Guard);
	CSListPopBack(&Guard);
	CSListPrint(&Guard);
	int ret = CSListFind(&Guard, 0);
	printf("%d\n", CSListPosPop(&Guard, ret));
	CSListPrint(&Guard);

	printf("%d\n", CSListSize(&Guard));

	CSListDestroy(&Guard);
}

int main()
{
	test();
	return 0;
}