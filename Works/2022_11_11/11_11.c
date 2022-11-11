#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void is_king(int arr[1000], int N)
{
	int count = 0;
	int tmp = 1;
	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}

	while (tmp < N)
	{
		for (int i = 1; i <= N; i++)
		{
			if (arr[i] != 0)
			{
				count++;
				if (count % 3 == 0)
				{
					arr[i] = 0;
				}
				if (arr[i] == 0)
				{
					tmp++;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] != 0)
		{
			printf("%d\n", arr[i]);
		}
	}

}

int main()
{
	int N = 0;
	int arr[1000] = { 0 };
	scanf("%d", &N);
	is_king(arr, N);
	return 0;
}


//int main()
//{
//	srand((unsigned int) time(NULL));
//	for (int i = 0; i < 100; i++)
//	{
//		int x = (rand() % 9 + 1);
//		int y = (rand() % 9 + 1);
//		printf("%d %d\n", x, y);
//	}
//	
//	return 0;
//}