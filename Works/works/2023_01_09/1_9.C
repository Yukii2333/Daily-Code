#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void swap(char*e1,char*e2,size_t width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}

void my_qsort(void* base, size_t sz, size_t width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1; j++)
		{
			if (cmp((char*)base+j*width,(char*)base+(j+1)*width) > 0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}

		}
	}
}

int compar(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), compar);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}

//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int compar_struct(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
//int main()
//{
//	struct Stu arr[3] = { { "laowang",45 }, { "niuyeye",69 }, { "jiankang",30 } };
//	qsort(arr, 3, sizeof(arr[0]), compar_struct);
//	return 0;
//}

//int compar_char(const void* e1, const void* e2)
//{
//	return *(char*)e2 - *(char*)e1;
//}
//
//int main()
//{
//	char arr[] = "abcdefg";
//	int sz = strlen(arr);
//	qsort(arr, sz, sizeof(char), compar_char);
//	printf("%s\n", arr);
//	return 0;
//}

//int compar(const void* e1, const void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), compar);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}