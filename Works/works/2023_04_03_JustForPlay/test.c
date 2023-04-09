#include"CircularSingleList.h"
#include"SLT.h"

void test()
{
	CSLTNode Guard;
	SLTNode* SLT = NULL;
	CSListInit(&Guard);
	CSListPushBack(&Guard, 0);
	CSListPushBack(&Guard, 1);
	CSListPushBack(&Guard, 2);
	CSListPushBack(&Guard, 3);
	CSListPushBack(&Guard, 4);
	CSListPushBack(&Guard, 5);
	CSListPushBack(&Guard, 6);
	CSListPrint(&Guard);
	printf("%d\n", CSListSize(&Guard));
	while (CSListSize(&Guard)>1)
	{
		SLTPushBack(&SLT, CSListPosPop2(&Guard,7));
	}
	SLTPrint(SLT);
	printf("last number:");
	CSListPrint(&Guard);
	CSListDestroy(&Guard);
}

int main()
{
	test();
	return 0;
}