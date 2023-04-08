#include"Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//选择排序
//时间复杂度O(N^2)
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

//三数取中
int GrtMidNum(int* a, int left, int right)
{
	int mid_i = (left + right) / 2;
	if (a[left] > a[right])
	{
		if (a[mid_i] > a[left])
		{
			return left;
		}
		else if (a[mid_i]<a[right])
		{
			return right;
		}
		else
		{
			return mid_i;
		}
	}
	else
	{
		if (a[mid_i] > a[right])
		{
			return right;
		}
		else if (a[mid_i] < a[left])
		{
			return left;
		}
		else
		{
			return mid_i;
		}
	}
}

//递归快速排序
void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	//这种key_i对于有序排序时间复杂度较高
	//int key_i = left;

	//随机选key_y,在一定程度上能解决问题
	//int rand_i = left + (rand() % (right - left));
	//Swap(&a[left], &a[rand_i]);

	//三数取中，相比随机更能解决问题
	int mid_i = GrtMidNum(a, left, right);
	if (mid_i != left)
	{
		Swap(&a[left], &a[mid_i]);
	}

	int key_i = left;
	int began = left;
	int end = right;
	while (left<right)
	{
		while (left < right && a[right] >= a[key_i])
		{
			--right;
		}
		while (left < right && a[left] <= a[key_i])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key_i], &a[left]);
	//此时left和right指向的位置相同，且是key的正确位置，因此不用考虑
	key_i = left;
	QuickSort1(a, began, key_i - 1);
	QuickSort1(a, key_i + 1, end);
}

//快排，递归挖坑法
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid_i = GrtMidNum(a, left, right);
	if (mid_i != left)
	{
		Swap(&a[left], &a[mid_i]);
	}
	int key = a[left];
	int hole = left;
	int began = left;
	int end = right;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	QuickSort2(a, began, hole - 1);
	QuickSort2(a, hole + 1, end);
}

//前两种递归模块化
int PartSort1(int* a, int left, int right)
{
	int mid_i = GrtMidNum(a, left, right);
	if (mid_i != left)
	{
		Swap(&a[left], &a[mid_i]);
	}
	int key_i = left;
	int began = left;
	int end = right;
	while (left < right)
	{
		while (left < right && a[right] >= a[key_i])
		{
			--right;
		}
		while (left < right && a[left] <= a[key_i])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key_i], &a[left]);
	key_i = left;
	return key_i;
}

int PartSort2(int* a, int left, int right)
{
	int mid_i = GrtMidNum(a, left, right);
	if (mid_i != left)
	{
		Swap(&a[left], &a[mid_i]);
	}
	int key = a[left];
	int hole = left;
	int began = left;
	int end = right;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

//双指针法
//cur找到比key小的值，先++prev然后交换cur与prev处的值，再++cur
//cur找到比key大的值，++cur
int PartSort3(int* a, int left, int right)
{
	int mid_i = GrtMidNum(a, left, right);
	if (mid_i != left)
	{
		Swap(&a[left], &a[mid_i]);
	}
	int key_i = left;
	int cur = left;
	int prev = cur;
	while (cur <= right)
	{
		if (a[cur] < a[key_i] && prev++ != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[key_i], &a[prev]);
	key_i = prev;
	return key_i;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = PartSort3(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}