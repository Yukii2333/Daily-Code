#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Swap(int* p1, int* p2);

//ѡ������
void SelectSort(int* a, int n);

//����
void HeapSort(int* a, int n);
//���µ���
void AdjustDown(int* a, int n, int parent);

//ð������
void BubbleSort(int* a, int n);

//�ݹ��������
void QuickSort(int* a, int left, int right);