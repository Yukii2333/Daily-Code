#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//实现对输入值单独打印
//void Printf(int n)
//{
//
//	if (n > 9)
//	{
//		Printf(n / 10);
//	}
//	
//	n = n % 10;
//	printf("%d ", n);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	Printf(n);
//	return 0;
//}

//递归实现strlen函数
//int my_strlen(char* arr)
//{
//
//	if(*arr != '\0')
//	{ 
//		return 1 + my_strlen(arr + 1);
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//
//int main()
//{
//	char arr[] = "bit!!!";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//非递归实现strlen函数
//int my_strlen(char* arr)
//{
//	int count = 0;
//
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;//arr是字符指针，*arr是内的字符,arr+1就向后跳一个字符
//	}
//
//	return count;
//}
//
//int main()
//{
//	char arr[] = "bit!";
//	int len = my_strlen(arr);//传递arr时，先传递arr[0] = "b"
//	printf("%d\n", len);
//	return 0;
//}

//递归 求输入数个位的和
//int DigitSum(int in)
//{
//
//	if (in > 9)
//	{
//		return (DigitSum(in / 10) + in % 10);//1729==》172+9==》17+2+9==》1+712+9
//	}
//	else
//	{
//		return in;
//	}
//
//}
//
//int main()
//{
//	int in = 0;
//	scanf("%d", &in);
//	int out = DigitSum(in);
//	printf("%d\n", out);
//	return 0;
//}

//递归 k的n次方
//double power(int n, int k)
//{
//
//	if (k > 0)
//	{
//		return n * power(n, k - 1);
//	}
//	else if (k == 0)
//	{
//		return 1;
//	}
//	else if (k < 0)
//	{
//		return (1.0 / power(n, -k));//先求倒数
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double end = power(n, k);//k小于1会有小数，不能用整形,float和double好像都行
//	printf("%lf\n", end);
//	return 0;
//}

//int main()       //邦邦环节
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	
//	if (a < 1000)
//	{
//		b = sqrt(a);
//		printf("平方根为 %d\n", b);
//	}
//	else
//	{
//		printf("请输入一个小于1000的数");
//	}
//
//	return 0;
//}