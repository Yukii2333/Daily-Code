#include"CircularSingleList.h"

//创建
void CSListInit(CSLTNode* Guard)
{
	assert(Guard);
	Guard->data = 0;
	Guard->next = Guard;
}

//判空
bool CSListEmpty(CSLTNode* Guard)
{
	assert(Guard);
	return Guard->next == Guard;
}

//销毁，最后指针置空需要自己操作
void CSListDestroy(CSLTNode* Guard)
{
	assert(Guard);
	CSLTNode* cur = Guard->next;
	while (cur != Guard)
	{
		CSLTNode* tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	cur->next = NULL;
}

//头插
void CSListPushFront(CSLTNode* Guard, CSLTDataType x)
{
	assert(Guard);
	CSLTNode* newnode = (CSLTNode*)malloc(sizeof(CSLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = Guard->next;
	Guard->next = newnode;
}

//打印
void CSListPrint(CSLTNode* Guard)
{
	assert(Guard);
	CSLTNode* cur = Guard->next;
	while (cur != Guard)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//头删
void CSListPopFront(CSLTNode* Guard)
{
	assert(Guard);
	assert(!CSListEmpty(Guard));
	CSLTNode* cur = Guard->next;
	Guard->next = cur->next;
	free(cur);
}

//尾插
void CSListPushBack(CSLTNode* Guard, CSLTDataType x)
{
	assert(Guard);
	CSLTNode* newnode = (CSLTNode*)malloc(sizeof(CSLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	CSLTNode* tail = Guard->next;
	while (tail->next != Guard)
	{
		tail = tail->next;
	}
	newnode->next = tail->next;
	tail->next = newnode;
}

//尾删
void CSListPopBack(CSLTNode* Guard)
{
	assert(Guard);
	assert(!CSListEmpty(Guard));
	CSLTNode* tail = Guard->next;
	while (tail->next->next != Guard)
	{
		tail = tail->next;
	}
	free(tail->next);
	tail->next = Guard;
}

//查找,返回相对位置（Guard为0位置）
int CSListFind(CSLTNode* Guard, CSLTDataType n)
{
	assert(Guard);
	CSLTNode* cur = Guard->next;
	int pos = 1;
	while (cur != Guard)
	{
		if (cur->data == n)
		{
			return pos;
		}
		cur = cur->next;
		pos++;
	}
	return 0;
}

//大小
int CSListSize(CSLTNode* Guard)
{
	assert(Guard);
	int size = 0;
	CSLTNode* cur = Guard->next;
	while (cur != Guard)
	{
		++size;
		cur = cur->next;
	}
	return size;
}

//指定位置删除（位置规则跟查找一样）
//返回删除的值
CSLTDataType CSListPosPop(CSLTNode* Guard, int pos)
{
	assert(Guard);
	assert(!CSListEmpty(Guard));
	int size = CSListSize(Guard);
	assert(pos <= size && pos > 0);
	CSLTNode* cur = Guard;
	while (--pos)
	{
		cur = cur->next;
	}
	CSLTNode* tmp = cur->next;
	cur->next = tmp->next;
	CSLTDataType ret = tmp->data;
	free(tmp);
	return ret;
}