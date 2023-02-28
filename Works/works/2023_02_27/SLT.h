#define _CRT_SECURE_NO_WARNINGS 1
#pragma

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

// slist.h
typedef int SLTDateType;
typedef struct SLTNode
{
	SLTDateType data;
	struct SLTNode* next;
}SLTNode;

// 动态申请一个节点
SLTNode* BuySListNode(SLTDateType x);
// 单链表打印
void SLTPrint(SLTNode* phead);
// 单链表尾插
void SLTPushBack(SLTNode** pplist, SLTDateType x);
// 单链表的头插
void SLTPushFront(SLTNode** pplist, SLTDateType x);
// 单链表的尾删
void SLTPopBack(SLTNode** pplist);
// 单链表头删
void SLTPopFront(SLTNode** pplist);
// 单链表查找
SLTNode* SLTFind(SLTNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SLTInsertAfter(SLTNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SLTEraseAfter(SLTNode* pos);
// 单链表的销毁
void SLTDestroy(SLTNode** pplist);