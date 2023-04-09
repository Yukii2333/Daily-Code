#include"CircularSingleList.h"

//����
void CSListInit(CSLTNode* Guard)
{
	assert(Guard);
	Guard->data = 0;
	Guard->next = NULL;
}

//�п�
bool CSListEmpty(CSLTNode* Guard)
{
	assert(Guard);
	return Guard->next == NULL;
}

//���٣����ָ���ÿ���Ҫ�Լ�����
void CSListDestroy(CSLTNode* Guard)
{
	assert(Guard);
	assert(!CSListEmpty(Guard));
	CSLTNode* cur = Guard->next->next;
	while (cur != Guard->next)
	{
		CSLTNode* tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(Guard->next);
	Guard->next = NULL;
}

//ͷ��
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
	newnode->next = NULL;
	if (Guard->next == NULL)
	{
		Guard->next = newnode;
		newnode->next = newnode;
	}
	else
	{
		CSLTNode* tail = Guard->next;
		while (tail->next != Guard->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
		newnode->next = Guard->next;
		Guard->next = newnode;
	}
}

//��ӡ
void CSListPrint(CSLTNode* Guard)
{
	assert(Guard);
	if (Guard->next == NULL)
	{
		return;
	}
	CSLTNode* cur = Guard->next;
	while (cur->next != Guard->next)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("%d \n", cur->data);
}

//ͷɾ
void CSListPopFront(CSLTNode* Guard)
{
	assert(Guard);
	assert(!CSListEmpty(Guard));
	CSLTNode* cur = Guard->next;
	if (cur->next == cur)
	{
		Guard->next = NULL;
	}
	else
	{
		CSLTNode* tail = Guard->next;
		while (tail->next != cur)
		{
			tail = tail->next;
		}
		tail->next = cur->next;
		Guard->next = cur->next;
	}
	free(cur);
}

//β��
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
	if (tail == NULL)
	{
		Guard->next = newnode;
		newnode->next = newnode;
	}
	else
	{
		while (tail->next != Guard->next)
		{
			tail = tail->next;
		}
		newnode->next = tail->next;
		tail->next = newnode;
	}
}

//βɾ
void CSListPopBack(CSLTNode* Guard)
{
	assert(Guard);
	assert(!CSListEmpty(Guard));
	CSLTNode* tail = Guard->next;
	if (tail->next == tail)
	{
		free(tail);
		Guard->next = NULL;
	}
	else
	{
		while (tail->next->next != Guard->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = Guard->next;
	}
}

//����,�������λ��
int CSListFind(CSLTNode* Guard, CSLTDataType n)
{
	assert(Guard);
	assert(!CSListEmpty(Guard));
	CSLTNode* cur = Guard->next;
	int pos = 1;
	if (cur->next == cur && cur->data == n)
	{
		return pos;
	}
	while (cur->next != Guard->next)
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

//��С
int CSListSize(CSLTNode* Guard)
{
	assert(Guard);
	if (Guard->next == NULL)
	{
		return 0;
	}
	int size = 1;
	CSLTNode* cur = Guard->next;
	while (cur->next != Guard->next)
	{
		++size;
		cur = cur->next;
	}
	return size;
}

//ָ��λ��ɾ����λ�ù��������һ����
//����ɾ����ֵ
CSLTDataType CSListPosPop(CSLTNode* Guard, int pos)
{
	assert(Guard);
	assert(!CSListEmpty(Guard));
	int size = CSListSize(Guard);
	assert(pos <= size && pos > 0);
	CSLTNode* cur = Guard;
	CSLTNode* tail = Guard->next;
	if (pos == 1)
	{
		while (tail->next != Guard->next)
		{
			tail = tail->next;
		}
		tail->next = cur->next->next;
	}
	while (--pos)
	{
		cur = cur->next;
	}
	CSLTNode* tmp = cur->next;
	if (size == 1)
	{
		cur->next = NULL;
	}
	else
	{
		cur->next = tmp->next;
	}
	CSLTDataType ret = tmp->data;
	free(tmp);
	return ret;
}

CSLTDataType CSListPosPop2(CSLTNode* Guard, int pos)
{
	assert(Guard);
	assert(!CSListEmpty(Guard));
	int size = CSListSize(Guard);
	assert(pos > 0);
	CSLTNode* cur = Guard;
	CSLTNode* tail = Guard->next;
	if (pos == 1)
	{
		while (tail->next != Guard->next)
		{
			tail = tail->next;
		}
		tail->next = cur->next->next;
	}
	while (--pos)
	{
		cur = cur->next;
	}
	CSLTNode* tmp = cur->next;
	if (size == 1)
	{
		cur->next = NULL;
	}
	else
	{
		Guard->next = cur;
		cur->next = tmp->next;
	}
	CSLTDataType ret = tmp->data;
	free(tmp);
	return ret;
}