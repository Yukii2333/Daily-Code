#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void main()
{
	int n = 0;
	int i = 0; 
	int e[100] = { 0 };
	int c = 0;;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &e[i]);
	}

	c = e[0];
	for (i = 0; i < n; i++)
	{

		if (e[i] > c)
		{
			c = e[i];
		}
	}

	printf("%d\n", c);
}