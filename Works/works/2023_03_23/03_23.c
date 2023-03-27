#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//������
//���򽨴��
//����С��
void HeapSort(int* a, int n)
{
	assert(a);

	//���µ������ѣ���ѣ�
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//���µ�������
	for (int i = n-1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}

int main()
{
	int arr[10] = { 9,5,6,7,8,1,23,3,4,5 };
	printf("ԭʼ��");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	HeapSort(arr, 10);
	printf("���ţ�");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}