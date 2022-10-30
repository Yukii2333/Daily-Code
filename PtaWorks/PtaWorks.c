#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>


//void mul( a)
//{
//	short b = 0;
//
//	for (int i = 1; i <= a; i++)
//	{
//		
//		for (int c = 1; c <= i; c++)
//		{
//			b = i * c;
//			printf("%d*%d=%-4d", c, i, b);//%-4d意思是数字占四位、左对齐
//		}
//		if (i != a)
//		{
//			printf("\n");
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	mul(a);//求输入数的乘法表函数mul
//	return 0;
//}

//int main()
//{
//	int sc1 = 0, sc2 = 0, sc3 = 0, sc4 = 0, sc5 = 0;
//	float aver = 0;
//	scanf("%d %d %d %d %d", &sc1, &sc2, &sc3, &sc4, &sc5);
//	aver = (sc1 + sc2 + sc3 + sc4 + sc5) / 5.0;
//	printf("%.1f\n", aver);
//	return 0;
//}

//int main()
//{
//	int on = 0, te = 0, hu = 0, th = 0;
//	scanf("%d %d %d %d", &on, &te, &hu, &th);
//	int p = on + te * 10 + hu * 100 + th * 1000;
//	printf("%d\n", p);
//	return 0;
//}

//float S(float L1, float L2, float L3)
//{
//	float s = 0;
//	float c = (L1 + L2 + L3) / 2;
//	s = sqrt(c * (c - L1) * (c - L2) * (c - L3));
//	return s;
//}
//
//int main()
//{
//	float L1 = 0, L2 = 0, L3 = 0;
//	float s = 0;
//	scanf("%f,%f,%f", &L1, &L2, &L3);
//	s = S(L1, L2, L3);
//	printf("%.2f\n", s);
//	return 0;
//}

//int main()
//{
//	int V = 0;
//	int L = 0, W = 0, H = 0;
//	scanf("%d %d %d", &L, &W, &H);
//	V = L * W * H;
//	printf("%d\n", V);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	b = a * a * a;
//	printf("%d\n", b);
//	return 0;
//}

//int add(a)
//{
//	int b = 0;
//
//	for (int i = 1; i <= a; i++)
//	{
//		b = b + i;
//	}
//
//	return b;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int sum = add(a);
//	printf("%d", sum);
//	return 0;
//}