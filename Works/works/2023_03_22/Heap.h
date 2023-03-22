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

// 堆的构建
void HeapInit(HP* hp);
// 堆的销毁
void HeapDestory(HP* hp);
// 堆的插入
void HeapPush(HP* hp, HPDataType x);
// 堆的删除
void HeapPop(HP* hp);
// 取堆顶的数据
HPDataType HeapTop(HP* hp);
// 堆的数据个数
int HeapSize(HP* hp);
// 堆的判空
bool HeapEmpty(HP* hp);