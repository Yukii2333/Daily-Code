#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct Stu
{
    int a;
    char b;
    int c;
}s1;

int main()
{
	printf("%d\n", sizeof(s1));
	return 0;
}

//my_memmove(char* p1, const char* p2, int sz)
//{
//	sz--;
//	while (sz != 0)
//	{
//		sz--;
//		*(p1+sz) = *(p2+sz);
//	}
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	my_memmove(&arr1[1],arr1, 16);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

//void my_memcpy(char* p1, const char* p2, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		*p1 = *p2;
//		p1++;
//		p2++;
//	}
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int arr2[4] = { 0 };
//	my_memcpy(arr2, arr1, 16);
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}