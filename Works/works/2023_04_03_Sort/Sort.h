#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Stack.h"

void Swap(int* p1, int* p2);

void InsertSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//����
void HeapSort(int* a, int n);
//���µ���
void AdjustDown(int* a, int n, int parent);

//ð������
void BubbleSort(int* a, int n);

//�ݹ��������,������
void QuickSort1(int* a, int left, int right);
//����ȡ�У������м�ֵ�±�
int GrtMidNum(int* a, int left, int right);

//���ţ��ݹ��ڿӷ�
void QuickSort2(int* a, int left, int right);


//ǰ���ֵݹ�ģ�黯
int PartSort1(int* a, int left, int right);

int PartSort2(int* a, int left, int right);

//˫ָ�뷨
int PartSort3(int* a, int left, int right);

void QuickSort(int* a, int left, int right);