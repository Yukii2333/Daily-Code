#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//ѭ������
//��ͷ
typedef int CSLTDataType;

typedef struct CSLTNode
{
	CSLTDataType data;
	struct CSLTNode* next;
}CSLTNode;

//����
void CSListInit(CSLTNode* Guard);

//�п�
bool CSListEmpty(CSLTNode* Guard);

//����
void CSListDestroy(CSLTNode* Guard);

//ͷ��
void CSListPushFront(CSLTNode* Guard, CSLTDataType x);

//β��
void CSListPushBack(CSLTNode* Guard, CSLTDataType x);

//ͷɾ
void CSListPopFront(CSLTNode* Guard);

//βɾ
void CSListPopBack(CSLTNode* Guard);

//��С
int CSListSize(CSLTNode* Guard);

//����,�������λ�ã�GuardΪ0λ�ã���δ�ҵ�����0
int CSListFind(CSLTNode* Guard, CSLTDataType n);

//ָ��λ��ɾ����λ�ù��������һ����
CSLTDataType CSListPosPop(CSLTNode* Guard, int pos);

//��ӡ
void CSListPrint(CSLTNode* Guard);