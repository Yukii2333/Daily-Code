#define _CRT_SECURE_NO_WARNINGS 1+

#include"Queue.h"

bool QueueEmpty(Queue* pq)//判断队列是否为空
{
	assert(pq);
	return pq->size == 0;
}

void QueueInit(Queue* pq)//队列初始化
{
	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	pq->head = pq->tail = tmp;
	pq->tail->next = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)//链表释放内存要一个一个节点释放
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	if(pq->size != 0)
	{
		QNode* tmp = (QNode*)malloc(sizeof(QNode));
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}
		pq->tail->next = tmp;
		pq->tail = tmp;
		pq->tail->next = NULL;
	}
	pq->tail->x = x;
	pq->size++;
}

void QueuePop(Queue* pq)//出队
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QNode* tmp = pq->head->next;
	if (pq->size == 1)
	{
		pq->size--;
	}
	else
	{
		free(pq->head);
		pq->head = tmp;
		pq->size--;
	}
}

int QueueSize(Queue* pq)//队列元素个数
{
	assert(pq);
	return pq->size;
}

QDataType QueueFront(Queue* pq)//队头元素
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->x;
}

QDataType QueueBack(Queue* pq)//队尾元素
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->x;
}