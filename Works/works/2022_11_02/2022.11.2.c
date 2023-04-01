#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int x = 0;//¸Ö±Ê5
	int y = 0;//Ç©×Ö±Ê3
	int z = 0;//Ç¦±Ê1/3
	int M = 0;//MÔª
	int N = 0;//NÖ§
	scanf("%d %d", &M, &N);

	for (x = 1; x < N - 4; x++)
	{

		for (y = 1; y < N - 4; y++)
		{
			
			for (z = 3; z < N - 2; z++)
			{

				if (z % 3 == 0)
				{

					if (N == x + y + z && M== 5 * x + 3 * y + z / 3)
					{
						printf("%d,%d,%d\n", x, y, z);
					}

				}


			}

		}

	}

	return 0;
}

//int main()
//{
//    int cases = 0;
//    scanf("%d", &cases);
//    getchar();
//    
//    while (cases--)
//    {
//        int sex = 0;
//        int tall = 0;
//        int wight = 0;
//        scanf("%d %d %d", &sex, &tall, &wight);
//        int flag = 0;
//       
//        if (sex == 0)
//        {
//            flag = 1;
//        }
//        if (tall < 130 - flag)
//        {
//            printf("duo chi yu! ");
//        }
//        if (tall == 130 - flag)
//        {
//            printf("wan mei! ");
//        }
//        if (tall > 130 - flag)
//        {
//            printf("ni li hai! ");
//        }
//        if (wight < 27 - flag * 2)
//        {
//            printf("duo chi rou!\n");
//        }
//        if (wight == 27 - flag * 2)
//        {
//            printf("wan mei!\n");
//        }
//        if (wight > 27 - flag * 2)
//        {
//            printf("shao chi rou!\n");
//        }
//
//    }
//
//    return 0;
//}

//int main()
//{
//    int j = 0;
//    int m = 0;
//    int n = 0;
//    scanf("%d", &m);
//    n = (m + 1) / 2;
//    
//    for (int i = 1; i <= n; i++)
//    {
//        
//        for (j = 2 * (n - i); j > 0; j--)
//        {
//            printf(" ");
//        }
//        
//        for (j = 1; j <= 2 * i - 1; j++)
//        {
//            printf("* ");
//        }
//
//        printf("\n");
//    }
//    
//    for (int i = 1; i <= n - 1; i++)
//    {
//       
//        for (j = 1; j <= 2 * i; j++)
//        {
//            printf(" ");
//        }
//        
//        for (j = 2 * (n - 1 - i) + 1; j > 0; j--)
//        {
//            printf("* ");
//        }
//
//        printf("\n");
//    }
//
//}

//int main()
//{
//	int n = 0;
//	int arr[20000] = { 0 };
//	int sum = 0;
//	float ave = 0;
//	int max = 0;
//	int min = 0;
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	max = arr[0];
//	min = arr[0];
//
//	for (int i = 0; i < n; i++)
//	{
//
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//		if (arr[i] < min)
//		{
//			min = arr[i];
//		}
//
//		sum = sum + arr[i];
//	}
//
//	ave = (sum - max - min) * 1.0 / (n - 2);
//	printf("%.1f\n", ave);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	float i = 0, m = 2, n = 1, p = 0;
//	int N = 0;
//	scanf("%d", &N);
//
//	for (a = 1; a <= N; a++)
//	{
//		i = i + m / n;
//		p = m;
//		m = m + n;
//		n = p;
//	}
//
//	printf("%.3f\n", i);
//	return 0;
//}