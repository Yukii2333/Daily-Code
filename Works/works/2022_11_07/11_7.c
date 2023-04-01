#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
		{
			printf("%d ", arr[i]);
		}
		else
		{
			printf("%d\n", arr[i]);
		}

	}

}

void sort(int arr[], int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

}

int main()
{
	int arr[10] = { 0 };
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, n);
	print(arr, n);
	return 0;
}

//int main()
//{
//    int a[1010] = { 0 };
//    int i, n, c = 0;
//    while (scanf("%d", &n), n >= 0)
//    {
//        a[n]++;
//    }
//    for (n = 100; n >= 0; n--)
//    {
//        if (c == 3)
//            break;
//        if (a[n] > 0)
//        {
//            while (a[n] > 0)
//            {
//                if (c == 3)
//                    break;
//                if (c == 0)
//                    printf("%d", n);
//                else
//                    printf(" %d", n);
//                c++;
//                a[n]--;
//            }
//        }
//    }
//    while (c < 3)
//    {
//        if (c == 0)
//            printf("#");
//        else
//            printf(" #");
//        c++;
//    }
//    printf("\n");
//    return 0;
//}

//void print(int arr[], int sz)//Ã°ÅÝÅÅÐò
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//
//	printf("\n");
//}
//
//void sort(int arr[], int sz)
//{
//
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//
//		print(arr, sz);
//	}
//	
//}
//
//int main()
//{
//	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	sort(arr, sz);
//	return 0;
//}

//int number(int z)//Êý¼¦µ°
//{
//	int num = 0;
//
//	for (int i = 0;; i++)
//	{
//		
//		if (i % 3 == 1 && i % 5 == z && i % 7 == 3)
//		{
//			return i;
//		}
//
//	}
//
//}
//
//int main()
//{
//	int y = 0;
//	int z = 0;
//	int i_v = 0;
//	scanf("%d %d", &y, &z);
//	i_v = number(z) + y;
//	printf("%d\n", i_v);
//	return 0;
//}

//void average(double arr[], int n)//µ÷ºÍÆ½¾ùÊý
//{
//	double sum = 0.0;
//	double ave = 0.0;
//	double result = 0.0;
//	
//	for (int i = 0; i < n; i++)
//	{
//		double tmp = 1.0 / arr[i];
//		sum = sum + tmp;
//	}
//
//	ave = sum / n;
//	result = 1.0 / ave;
//	printf("%.2lf\n", result);
//}
//
//int main()
//{
//	int n = 0;
//	double arr[1000] = { 0 };
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%lf", &arr[i]);
//	}
//
//	average(arr, n);
//	return 0;
//}

//void date(int d)//´ºÏÄÇï¶¬
//{
//	int D = d % 100;
//
//	if (D >= 3 && D <= 5)
//	{
//		printf("spring\n");
//	}
//	else if (D >= 6 && D <= 8)
//	{
//		printf("summer\n");
//	}
//	else if (D >= 9 && D <= 11)
//	{
//		printf("autumn\n");
//	}
//	else
//	{
//		printf("winter\n");
//	}
//
//}
//
//int main()
//{
//	int d = 0;
//	scanf("%d", &d);
//	date(d);
//	return 0;
//}

//void date(int x)//ÐÇÆÚ
//{
//	switch (x)
//	{
//	case 1:
//		printf("Monday\n");
//		break;
//	case 2:
//		printf("Tuesday\n");
//		break;
//	case 3:
//		printf("Wednesday\n");
//		break;
//	case 4:
//		printf("Thursday\n");
//		break;
//	case 5:
//		printf("Friday\n");
//		break;
//	case 6:
//		printf("Saturday\n");
//		break;
//	case 7:
//		printf("Sunday\n");
//		break;
//	default:
//		printf("ÊäÈë´íÎó£¡\n");
//		break;
//	}
//}
//
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	date(x);
//	return 0;
//}