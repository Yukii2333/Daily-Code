#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void test()
{
	Queue Que;
	QueueInit(&Que);
	QueuePush(&Que, 1);
	QueuePush(&Que, 2);
	QueuePush(&Que, 3);
	QueuePush(&Que, 4);
	QueuePush(&Que, 5);
	printf("%d\n", QueueSize(&Que));
	QueuePop(&Que);
	printf("%d\n", QueueSize(&Que));
	QueuePop(&Que);
	printf("%d\n", QueueSize(&Que));
	QueuePop(&Que);
	printf("%d\n", QueueSize(&Que));
	QueuePop(&Que);
	printf("%d\n", QueueSize(&Que));
	QueuePop(&Que);
	printf("%d\n", QueueSize(&Que));
	QueuePush(&Que, 1);
	QueuePush(&Que, 2);
	QueuePush(&Que, 3);
	QueuePush(&Que, 4);
	QueuePush(&Que, 5);
	printf("%d\n", QueueSize(&Que));
	QueueDestroy(&Que);
}

int main()
{
	test();
	return 0;
}