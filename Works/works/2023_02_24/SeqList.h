#define _CRT_SECURE_NO_WARNINGS 1

// SeqList.h
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define INIT_NUM 10

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	int size;
	int capacity;
}SeqList;

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps);//初始化
void SeqListDestroy(SeqList* ps);//销毁

void SeqListPrint(SeqList* ps);//打印
void SeqListPushBack(SeqList* ps, SLDateType x);//后插
void SeqListPushFront(SeqList* ps, SLDateType x);//前插
void SeqListPopFront(SeqList* ps);//前删
void SeqListPopBack(SeqList* ps);//后删

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos);