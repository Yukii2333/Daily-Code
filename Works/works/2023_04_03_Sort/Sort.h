#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Swap(int* p1, int* p2);

//选择排序
void SelectSort(int* a, int n);

//堆排
void HeapSort(int* a, int n);
//向下调整
void AdjustDown(int* a, int n, int parent);

//冒泡排序
void BubbleSort(int* a, int n);

//递归快速排序
void QuickSort(int* a, int left, int right);