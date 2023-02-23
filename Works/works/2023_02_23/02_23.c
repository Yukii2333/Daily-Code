#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void rotate(int* nums, int numsSize, int k)
{
    int count = k % numsSize;
    while (count)
    {
        int tmp1 = *(nums + numsSize - 1);
        for (int i = numsSize - 1; i > 0; i--)
        {
            *(nums + i) = *(nums + i - 1);
        }
        *nums = tmp1;
        count--;
    }
}

int main()
{
	int k = 11;
	int arr1[7] = { 0,2,3,4,5,6,7 };
    rotate(arr1, 7, k);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr1[i]);
    }
	return 0;
}