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

// ��̬����һ���ڵ�
SLTNode* BuySListNode(SLTDateType x);
// �������ӡ
void SLTPrint(SLTNode* phead);
// ������β��
void SLTPushBack(SLTNode** pplist, SLTDateType x);
// �������ͷ��
void SLTPushFront(SLTNode** pplist, SLTDateType x);
// �������βɾ
void SLTPopBack(SLTNode** pplist);
// ������ͷɾ
void SLTPopFront(SLTNode** pplist);
// ���������
SLTNode* SLTFind(SLTNode* plist, SLTDateType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SLTInsertAfter(SLTNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SLTEraseAfter(SLTNode* pos);
// �����������
void SLTDestroy(SLTNode** pplist);