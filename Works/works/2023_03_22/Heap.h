#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

// �ѵĹ���
void HeapInit(HP* hp);
// �ѵ�����
void HeapDestory(HP* hp);
// �ѵĲ���
void HeapPush(HP* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(HP* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(HP* hp);
// �ѵ����ݸ���
int HeapSize(HP* hp);
// �ѵ��п�
bool HeapEmpty(HP* hp);