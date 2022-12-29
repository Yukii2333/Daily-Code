#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define INT_PTR int*

int main()
{
	INT_PTR a = 0;
	typedef int* int_ptr;
	int_ptr c = 0;
	//int arr[5 + 3] = { 1, 2, 3, 4, 5 };
	//char c[] = { '\x10', '\xa', '\8' };
	return 0;
}