#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a[4], min, yu, max = 0, flag1 = 0, flag2 = 0, temp1 = 0, temp2 = 0;
	for (int i = 0; i < 4; i++) 
	{
		scanf("%d", &a[i]);
	}
	scanf("%d %d", &min, &yu);
	for (int i = 0; i < 4; i++) 
	{
		if (max < a[i]) 
		{
			max = a[i];
		}//取最大值
	}
	for (int i = 0; i < 4; i++) 
	{
		if (max - a[i] > yu) 
		{
			flag1++;//判断差值是否在范围内
		}
		if (flag1 == 1) 
		{
			temp1 = i + 1;//只有一个轮胎阈值不符
			flag1 = 2;//跳出
		}
	}
	for (int i = 0; i < 4; i++) 
	{
		if (a[i] < min) 
		{
			flag2++;//判断轮胎是否低于最小值
		}
		if (flag2 == 1) 
		{
			temp2 = i + 1;//只有一个轮胎低于最小值
			flag2 = 2;//跳出
		}
	}
	if (flag1 == 0 && flag2 == 0) 
	{
		printf("Normal");
	}
	else if (flag1 == 2 && flag2 == 0) 
	{
		printf("Warning: please check #%d!", temp1);
	}
	else if (flag2 == 2 && flag1 == 0) 
	{
		printf("Warning: please check #%d!", temp2);
	}
	else if (flag2 == 2 && flag1 == 2 && temp2 == temp1) 
	{
		printf("Warning: please check #%d!", temp2);
	}
	else if (flag1 > 2 || flag2 > 2) 
	{
		printf("Warning: please check all the tires!");
	}
	return 0;
}

//void judge(int arr[6])
//{
//	int max = arr[0];
//	int min = arr[0];
//	int count1 = 0;
//	int count2 = 0;
//	int site1 = 0;
//	int site2 = 0;
//
//	for (int i = 0; i < 4; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		int tmp = max - arr[i];
//
//			if (tmp > arr[5])
//			{
//				count1++;
//				site1 = i + 1;
//			}
//			if (arr[i] < arr[4])
//			{
//				count2++;
//				site2 = i + 1;
//			}
//
//
//	}
//
//	if ((count1 == 0)||(count2 == 0))
//	{
//		printf("Normal\n");
//	}
//	if (count1 == 1 && count2 == 0)
//	{
//		printf("Warning: please check #%d!\n", site1);
//	}
//	if (count1 == 0 && count2 == 1)
//	{
//		printf("Warning: please check #%d!\n", site2);
//	}
//	if ((count1 > 1) || (count2 > 1)||(count1 == 1 && count2 == 1))
//	{
//		printf("Warning: please check all the tires!\n");
//	}
//	
//}
//
//void assign(int arr[6])
//{
//	for (int i = 0; i < 6; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[6] = { 0 };
//	assign(arr);
//	judge(arr);
//	return 0;
//}