#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int  black_hole_times(int n)
{
	int arr[4] = { 0 };
	int i = 0;
	int j = 0;
	int tmp = 0;
	int t = 4;
	while (t--)
	{
		arr[i] = n % 10;
		i++;
		n /= 10;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
			if (arr[i] < arr[j])//由大到小排列
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	int n1 = arr[3] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[0];//小
	int n2 = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];//大
	return (n2 - n1);
}

int main()
{
	int n = 0;
	int k = 0;
	int arr[100] = { 0 };
	int count2 = 0;
	scanf("%d", &k);
	while(k--)
	{
		int count = 0;
		scanf("%d", &n);
		while (n != 6174)
		{
			n = black_hole_times(n);
			count++;
		}
		arr[count2] = count;
		count2++;
	}
	for (int i = 0; i < count2; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}