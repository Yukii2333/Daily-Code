#include"MergeSort.h"

//递归
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	//分成[begin,mid][mid+1,end]两个子区间
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);
	//归并
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	_MergeSort(a, 0, n - 1, tmp);
//}

//非递归归并
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += gap * 2)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if(end2 >= n)
			{
				end2 = n - 1;
			}
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
}

void CountingSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	//找最大最小值
	int i = 0;
	for (i = 1; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int len = max - min + 1;
	//创建计数数组
	int* count = (int*)malloc(sizeof(int) * len);
	if (count == NULL)
	{
		perror("malloc fail");
		return;
	}
	//初始化数组
	memset(count, 0, len*sizeof(int));
	//进行计数
	i = 0;
	while (i < n)
	{
		count[a[i++] - min]++;
	}
	//覆盖回原数组
	i = 0;
	int j = 0;
	while (i < len)
	{
		if (count[i] <= 0)
			++i;
		else
		{
			while (count[i]-- > 0)
			{
				a[j++] = i + min;
			}
		}
	}
}