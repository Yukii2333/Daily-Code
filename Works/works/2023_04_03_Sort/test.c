#include"Sort.h"

int main()
{
	int a[10] = { 0,5,6,8,7,1,9,4,2,3 };
	//SelectSort(a, 10);
	//HeapSort(a, 10);
	//BubbleSort(a, 10);
	//QuickSort1(a, 0, 9);
	//QuickSort2(a, 0, 9);
	QuickSort(a, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
	int b = 0;
	return 0;
}