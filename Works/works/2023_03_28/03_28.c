#include<stdio.h>

int main()
{
	printf("Hello World!\n");
	return 0;
}

/*
int k = 0;
while (k < n - gap)
{
	for (int i = k; i < n - gap; i += gap)
	{
		int gap = 3;
		int end = i;
		int tmp = a[end + gap];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			else
			{
				break;
			}
		}
		a[end + gap] = tmp;
	}
	k += gap;
}
*/
