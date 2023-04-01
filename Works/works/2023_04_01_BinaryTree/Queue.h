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

//��װͷβָ���Լ���С��ʹ���θ����
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pq);//���г�ʼ��
void QueueDestroy(Queue* pq);//��������
void QueuePush(Queue* pq, QDataType x);//���
void QueuePop(Queue* pq);//����
bool QueueEmpty(Queue* pq);//�ж϶����Ƿ�Ϊ��
int QueueSize(Queue* pq);//����Ԫ�ظ���
QDataType QueueFront(Queue* pq);//��ͷԪ��
QDataType QueueBack(Queue* pq);//��βԪ��