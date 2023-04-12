#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Stack.h"

void Swap(int* p1, int* p2);

void InsertSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//堆排
void HeapSort(int* a, int n);
//向下调整
void AdjustDown(int* a, int n, int parent);

//冒泡排序
void BubbleSort(int* a, int n);

//递归快速排序,基础版
void QuickSort1(int* a, int left, int right);
//三数取中，返回中间值下标
int GrtMidNum(int* a, int left, int right);

//快排，递归挖坑法
void QuickSort2(int* a, int left, int right);


//前两种递归模块化
int PartSort1(int* a, int left, int right);

int PartSort2(int* a, int left, int right);

//双指针法
int PartSort3(int* a, int left, int right);

void QuickSort(int* a, int left, int right);