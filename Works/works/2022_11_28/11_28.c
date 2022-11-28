#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



int fib(int n);

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", fib(n));

    return 0;
}

int fib(int n)
{
    if (n < 1) 
    {
        return 0;
    }
    else if (n == 1 || n == 2) 
    {
        return 1;
    }
    int f1 = 1;
    int f2 = 1;
    int tmp = 0;
    for (int i = 0; i < n - 2; i++)
    {
        tmp = f1;
        f1 += f2;
        f2 = tmp;
    }
    return f1;
}


//double fact(int n);
//
//int main(void)
//{
//    int i, n;
//    double sum;
//
//    scanf("%d", &n);
//    sum = 1;
//    for (i = 1; i <= n; i++) {
//        sum = sum + 1.0 / fact(i);
//    }
//    printf("%f\n", sum);
//
//    return 0;
//}
//
//double fact(int n)
//{
//    int i = 0;
//    double f = 1.0;
//    for (i = 1; i <= n; i++)
//    {
//        f *= i;
//    }
//    return f;
//}


//int sumday(int year, int month, int day);
//
//int main()
//{
//    int year, month, day, days;
//    scanf("%d/%d/%d", &year, &month, &day);
//    days = sumday(year, month, day);
//    printf("%d", days);
//    return 0;
//}
//
//int sumday(int year, int month, int day)
//{
//    int sum = 0;
//    switch (month)
//    {
//    case 1:sum = 0; 
//        break;
//    case 2:sum = 31;
//        break;
//    case 3:sum = 59;
//        break;
//    case 4:sum = 90;
//        break;
//    case 5:sum = 120; 
//        break;
//    case 6:sum = 151;
//        break;
//    case 7:sum = 181;
//        break;
//    case 8:sum = 212;
//        break;
//    case 9:sum = 243; 
//        break;
//    case 10:sum = 273; 
//        break;
//    case 11:sum = 304;
//        break;
//    case 12:sum = 334;
//        break;
//    default:printf("data error\n"); break;
//    }
//    if ((month > 2 && year % 4 == 0 && year % 100 != 0) || (month > 2 && year % 400 == 0))
//    {
//        sum += 1;
//    }
//    return sum + day;
//}


//int fun(int a, int n);
//
//int main()
//{
//
//    int a, n;
//    scanf("%d %d", &a, &n);
//    printf("%d", fun(a, n));
//
//    return 0;
//
//}
//
//int fun(int a, int n)
//{
//    int i = 0;
//    int tmp = a;
//    int sum = 0;
//    for (i = 0; i < n; i++)
//    {
//        sum += a;
//        a = a * 10 + tmp;
//    }
//    return sum;
//}

//int flower(int x);
//
//int main()
//{
//    int a, k;
//    scanf("%d", &a);
//    k = flower(a);
//    if (k)
//        printf("%d yes", a);
//    else
//        printf("%d no", a);
//    return 0;
//}
//
//int flower(int x)
//{
//    int one = x % 10;
//    int ten = x / 10 % 10;
//    int hun = x / 100;
//    return (one * one * one + ten * ten * ten + hun * hun * hun == x);
//}


//double Cash(double value);
//
//int main()
//{
//    double p, c;
//    scanf("%lg", &p);
//    c = Cash(p);
//    printf("%.2f\n", c);
//    return 0;
//}
//
//double Cash(double value)
//{
//    if (value < 100)
//    {
//        return value;
//    }
//    if (value >= 100 && value < 200)
//    {
//        return 0.95 * value;
//    }
//    if (value >= 200 && value < 500)
//    {
//        return 0.9 * value;
//    }
//    if (value >= 500 && value < 1000)
//    {
//        return 0.85 * value;
//    }
//    return 0.8 * value;
//}


//int fun(int a, int b);
//
//int main()
//{
//
//	int a, b;
//
//	scanf("%d %d", &a, &b);
//
//	printf("%d", fun(a, b));
//
//	return 0;
//
//}
//int fun(int a, int b)
//{
//	int i = 0;
//	int tmp = 0;
//	for (i = 1; i < a; i++)
//	{
//		if (a % i == 0 && b % i == 0)
//		{
//			tmp = i;
//		}
//	}
//	return tmp;
//}


//int FacSum(int n);
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    printf("%d", FacSum(n));
//    return 0;
//}
//int FacSum(int n)
//{
//    int i = 0;
//    int sum = 0;
//    for (i = 1; i < n; i++)
//    {
//        if (n % i == 0)
//        {
//            sum += i;
//        }
//    }
//    return sum;
//}

//int IntMin3(int x, int y, int z);
//
//int main()
//{
//    int a, b, c, d;
//    scanf("%d%d%d", &a, &b, &c);
//    d = IntMin3(a, b, c);
//    printf("%d\n", d);
//    return 0;
//}
//
//int IntMin3(int x, int y, int z)
//{
//    if (y > x && y > z)
//    {
//        return y;
//    }
//    if (x > y && x > z)
//    {
//        return x;
//    }
//    return z;
//}


//#include <stdio.h>
//
//int IntAbs(int x);
//
//int main()
//{
//    int a, b;
//    scanf("%d", &a);
//    b = IntAbs(a);
//    printf("%d\n", b);
//    return 0;
//}
//
//int IntAbs(int x)
//{
//    if (x < 0)
//    {
//        return x * -1;
//    }
//    return x;
//}

//double Sqr(double x);
//
//int main()
//{
//    double a, b;
//    scanf("%lg", &a);
//    b = Sqr(a);
//    printf("%g\n", b);
//    return 0;
//}
//
//double Sqr(double x)
//{
//    return x * x;
//}

//#define N 10
//
//int main()
//{
//	int i = 0;
//	int x = 0;
//	int n = 0;
//	int min = 0;
//	int max = 0;
//	int p = 0;
//	int q = 0;
//	int temp = 0;
//	int a[N] = { 0 };
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]); //&a[i] == a+i ==(a+i)
//	}
//	min = a[0];
//	for (i = 0; i < n; i++)
//	{
//		if (min >= a[i])
//		{
//			min = a[i];
//			p = i;
//		}
//	}
//	temp = a[0];
//	a[0] = a[p];
//	a[p] = temp;
//	max = a[0];
//	for (i = 0; i < n; i++)
//	{
//		if (max <= a[i])
//		{
//			max = a[i];
//			q = i;
//		}
//	}
//	temp = a[n - 1];
//	a[n - 1] = a[q];
//	a[q] = temp;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

//void exchange_max_min(int arr[10], int n)
//{
//	int i = 0;
//	int max = arr[0];
//	int min = arr[0];
//	int tmp = 0;
//	int count = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//		if (arr[i] < min)
//		{
//			min = arr[i];
//		}
//	}
//	tmp = arr[0];
//	arr[0] = min;
//	for (i = 1; i < n; i++)
//	{
//		if (arr[i] == min)
//		{
//			arr[i] = tmp;
//			break;
//		}
//	}
//	tmp = arr[n - 1];
//	arr[n - 1] = max;
//	for (i = 0; i < n - 1; i++)
//	{
//		if (arr[i] == max)
//		{
//			arr[i] = tmp;
//			break;
//		}
//	}
//}
//
//void assign(int arr[10], int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//	assign(arr, n);
//	exchange_max_min(arr, n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", &arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//int Max(int arr[10])
//{
//	int max = arr[0];
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	return max;
//}
//
//void assign(int arr[10])
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	assign(arr);
//	int max = Max(arr);
//	printf("%d\n", max);
//	return 0;
//}