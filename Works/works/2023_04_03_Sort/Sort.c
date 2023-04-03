#include"Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//选择排序
//时间复杂度O(N)
void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int min_i = left;
		int max_i = left;
		for (int i = left; i <= right; ++i)
		{
			if (a[i] < a[min_i])
			{
				min_i = i;
			}
			if (a[i] > a[max_i])
			{
				max_i = i;
			}
		}
		if (max_i == left)
		{
			max_i = min_i;
		}
		Swap(&a[left], &a[min_i]);
		Swap(&a[right], &a[max_i]);
		++left;
		--right;
	}
}

//堆排
//时间复杂度O(N*logN)
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}
//向下调整
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//冒泡排序
//时间复杂度O(N^2)
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		//少了这一判断无论情况好坏时间复杂度都为O(N^2)
		bool exchange = false;
		for (int i = 0; i < n - 1 - j; ++i)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = true;
			}
		}
		if (!exchange)
		{
			break;
		}
	}
}

//递归快速排序
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = left;
	int began = left;
	int end = right;
	while (left<right)
	{
		while (left < right && a[right] >= a[key])
		{
			--right;
		}
		while (left < right && a[left] <= a[key])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	//此时left和right指向的位置相同，且是key的正确位置，因此不用考虑
	QuickSort(a, began, left - 1);
	QuickSort(a, right + 1, end);
}