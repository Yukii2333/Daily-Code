#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include"BinaryTree.h"

typedef BTNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType x;
}QNode;

//封装头尾指针以及大小，使传参更简便
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pq);//队列初始化
void QueueDestroy(Queue* pq);//队列销毁
void QueuePush(Queue* pq, QDataType x);//入队
void QueuePop(Queue* pq);//出队
bool QueueEmpty(Queue* pq);//判断队列是否为空
int QueueSize(Queue* pq);//队列元素个数
QDataType QueueFront(Queue* pq);//队头元素
QDataType QueueBack(Queue* pq);//队尾元素