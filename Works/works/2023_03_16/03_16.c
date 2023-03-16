#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void test()
{
	ST stack;
	STInit(&stack);
	STPush(&stack, 1);
	STPush(&stack, 2);
	STPush(&stack, 3);
	STPush(&stack, 4);
	printf("%d\n", STSize(&stack));
	printf("%d\n", STTop(&stack));
	STPop(&stack);
	printf("%d\n", STTop(&stack));
	STPop(&stack);
	printf("%d\n", STTop(&stack));
	STPop(&stack);
	printf("%d\n", STTop(&stack));
	STDestroy(&stack);
}

int main()
{
	test();
	return 0;
}