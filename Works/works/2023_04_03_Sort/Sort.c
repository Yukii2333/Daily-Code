#include"Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//ѡ������
//ʱ�临�Ӷ�O(N^2)
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

//����ȡ��
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

//�ݹ��������
void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	//����key_i������������ʱ�临�ӶȽϸ�
	//int key_i = left;

	//���ѡkey_y,��һ���̶����ܽ������
	//int rand_i = left + (rand() % (right - left));
	//Swap(&a[left], &a[rand_i]);

	//����ȡ�У����������ܽ������
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
	//��ʱleft��rightָ���λ����ͬ������key����ȷλ�ã���˲��ÿ���
	key_i = left;
	QuickSort1(a, began, key_i - 1);
	QuickSort1(a, key_i + 1, end);
}

//���ţ��ݹ��ڿӷ�
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

//ǰ���ֵݹ�ģ�黯
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

//˫ָ�뷨
//cur�ҵ���keyС��ֵ����++prevȻ�󽻻�cur��prev����ֵ����++cur
//cur�ҵ���key���ֵ��++cur
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