#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define Exchange(num) ((((num) & (0X55555555)) << 1) | (((num) & (0XAAAAAAAA)) >> 1))

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d", Exchange(a));
	return 0;
}

//#define Offsetof(type,name) ((size_t)&(((type*)0)->name))
//
//struct Stu
//{
//	int a;
//	char b[20];
//	char c[20];
//};
//
//int main()
//{
//	printf("Stu��a��ƫ������%d\n", Offsetof(struct Stu, a));
//	printf("Stu��b��ƫ������%d\n", Offsetof(struct Stu, b));
//	printf("Stu��c��ƫ������%d\n", Offsetof(struct Stu, c));
//	return 0;
//}