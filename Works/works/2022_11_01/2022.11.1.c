#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//ʵ�ֶ�����ֵ������ӡ
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

//�ݹ�ʵ��strlen����
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

//�ǵݹ�ʵ��strlen����
//int my_strlen(char* arr)
//{
//	int count = 0;
//
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;//arr���ַ�ָ�룬*arr���ڵ��ַ�,arr+1�������һ���ַ�
//	}
//
//	return count;
//}
//
//int main()
//{
//	char arr[] = "bit!";
//	int len = my_strlen(arr);//����arrʱ���ȴ���arr[0] = "b"
//	printf("%d\n", len);
//	return 0;
//}

//�ݹ� ����������λ�ĺ�
//int DigitSum(int in)
//{
//
//	if (in > 9)
//	{
//		return (DigitSum(in / 10) + in % 10);//1729==��172+9==��17+2+9==��1+712+9
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

//�ݹ� k��n�η�
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
//		return (1.0 / power(n, -k));//������
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double end = power(n, k);//kС��1����С��������������,float��double������
//	printf("%lf\n", end);
//	return 0;
//}

//int main()       //����
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	
//	if (a < 1000)
//	{
//		b = sqrt(a);
//		printf("ƽ����Ϊ %d\n", b);
//	}
//	else
//	{
//		printf("������һ��С��1000����");
//	}
//
//	return 0;
//}