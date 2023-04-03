#include"Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//ѡ������
//ʱ�临�Ӷ�O(N)
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

//����
//ʱ�临�Ӷ�O(N*logN)
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
//���µ���
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

//ð������
//ʱ�临�Ӷ�O(N^2)
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		//������һ�ж���������û�ʱ�临�Ӷȶ�ΪO(N^2)
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

//�ݹ��������
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
	//��ʱleft��rightָ���λ����ͬ������key����ȷλ�ã���˲��ÿ���
	QuickSort(a, began, left - 1);
	QuickSort(a, right + 1, end);
}