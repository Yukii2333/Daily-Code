#include"Sort.h"

int main()
{
	int a[10] = { 0,5,6,8,7,1,9,4,2,3 };
	//SelectSort(a, 10);
	//HeapSort(a, 10);
	//BubbleSort(a, 10);
	QuickSort(a, 0, 9);
	int b = 0;
	return 0;
}