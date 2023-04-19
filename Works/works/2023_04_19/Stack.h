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

void STInit(ST* ps);//初始化栈

void STDestroy(ST* ps);//栈销毁

void STPush(ST* ps, STDataType x);//入栈

void STPop(ST* ps);//出栈

int STSize(ST* ps);//栈大小

bool STEmpty(ST* ps);//栈是否存在以及为空

STDataType STTop(ST* ps);//栈顶元素

