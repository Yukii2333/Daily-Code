#include"MergeSort.h"

int main()
{
	/*int* a = (int*)malloc(sizeof(int) * 114514);
	if (a == NULL)
		exit(-1);
	for (int i = 0; i < 114514; i++)
	{
		a[i] = rand();
	}
	MergeSort(a, 114514);*/
	int a[9] = { 1,4,3,2,3,1,4,5,7 };
	for (int i = 0; i < 9; ++i)
	{
		printf("%d ", a[i]);
	}
	CountingSort(a, 9);
	printf("\n");
	for (int i = 0; i < 9; ++i)
	{
		printf("%d ", a[i]);
	}
	int b = 0;
	return 0;
}