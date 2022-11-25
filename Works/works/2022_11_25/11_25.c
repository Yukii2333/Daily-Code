#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Add(int arr[10])
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int Sum = Add(arr);
	double Ave = Sum / 10.0;
	printf("Sum=%d\nAve=%.1f\n", Sum, Ave);
	return 0;
}