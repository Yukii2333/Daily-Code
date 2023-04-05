#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//循环链表
//带头
typedef int CSLTDataType;

typedef struct CSLTNode
{
	CSLTDataType data;
	struct CSLTNode* next;
}CSLTNode;

//创建
void CSListInit(CSLTNode* Guard);

//判空
bool CSListEmpty(CSLTNode* Guard);

//销毁
void CSListDestroy(CSLTNode* Guard);

//头插
void CSListPushFront(CSLTNode* Guard, CSLTDataType x);

//尾插
void CSListPushBack(CSLTNode* Guard, CSLTDataType x);

//头删
void CSListPopFront(CSLTNode* Guard);

//尾删
void CSListPopBack(CSLTNode* Guard);

//大小
int CSListSize(CSLTNode* Guard);

//查找,返回相对位置（Guard为0位置），未找到返回0
int CSListFind(CSLTNode* Guard, CSLTDataType n);

//指定位置删除（位置规则跟查找一样）
CSLTDataType CSListPosPop(CSLTNode* Guard, int pos);

//打印
void CSListPrint(CSLTNode* Guard);