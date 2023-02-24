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

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);//��ʼ��
void SeqListDestroy(SeqList* ps);//����

void SeqListPrint(SeqList* ps);//��ӡ
void SeqListPushBack(SeqList* ps, SLDateType x);//���
void SeqListPushFront(SeqList* ps, SLDateType x);//ǰ��
void SeqListPopFront(SeqList* ps);//ǰɾ
void SeqListPopBack(SeqList* ps);//��ɾ

// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, int pos);