#include"MergeSort.h"

int main()
{
	int* a = (int*)malloc(sizeof(int) * 114514);
	if (a == NULL)
		exit(-1);
	for (int i = 0; i < 114514; i++)
	{
		a[i] = rand();
	}
	clock_t t = clock();
	MergeSort(a, 114514);
	t = clock() - t;
	printf("%dms %fs\n", t, ((float)t) / CLOCKS_PER_SEC);
	int b = 0;
	return 0;
}