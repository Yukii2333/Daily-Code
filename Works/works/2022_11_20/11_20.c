#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//void upside_down(char* arr, int count)
//{
//    int i = 0;
//    for (i = 0; i < count; i++)
//    {
//        int tmp = *(arr + i);
//        *(arr + i) = *(arr + count - 1);
//        *(arr + count - 1) = tmp;
//        count--;
//    }
//}
//
//int main()
//{
//    char arr = "0";
//    int i = 0;
//    int count = 0;
//    scanf("%s", arr);
//    
//    upside_down(arr, count);
//    printf("%s\n", arr);
//    return 0;
//}

//void print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *arr);
//		arr++;
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//}