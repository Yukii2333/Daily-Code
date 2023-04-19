#define _CRT_SECURE_NO_WARNINGS 1

#pragma

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack 
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* ps);//��ʼ��ջ

void STDestroy(ST* ps);//ջ����

void STPush(ST* ps, STDataType x);//��ջ

void STPop(ST* ps);//��ջ

int STSize(ST* ps);//ջ��С

bool STEmpty(ST* ps);//ջ�Ƿ�����Լ�Ϊ��

STDataType STTop(ST* ps);//ջ��Ԫ��

