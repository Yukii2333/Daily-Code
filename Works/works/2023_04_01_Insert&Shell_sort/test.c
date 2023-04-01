#include"Insert&Shell_sort.h"

int main()
{
	int a[10] = { 9,3,5,6,8,4,7,2,1,0 };
	InsertSort(a, 10);
	//ShellSort(a, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}