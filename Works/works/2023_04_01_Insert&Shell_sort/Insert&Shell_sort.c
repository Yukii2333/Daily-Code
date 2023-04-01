#include"Insert&Shell_sort.h"

void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int end = i - 1;
		int tmp = a[i];

		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = gap; i < n; ++i)
		{
			int end = i - gap;
			int tmp = a[i];

			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
		for (int i = 0; i < 10; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}