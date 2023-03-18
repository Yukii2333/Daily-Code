#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

typedef char STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

bool STEmpty(ST* ps)//ÅÐ¶ÏÕ»µÄ×´Ì¬
{
	assert(ps);
	return ps->top == 0;
}

void STInit(ST* ps)//Õ»³õÊ¼»¯
{
	STDataType* a = (STDataType*)malloc(sizeof(STDataType) * 8);
	if (!a)
	{
		perror("malloc fail");
		return;
	}
	ps->a = a;
	ps->capacity = 8;
	ps->top = 0;
}

void STPush(ST* ps, STDataType x)//ÈëÕ»
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* a = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
		if (!a)
		{
			perror("malloc fail");
			return;
		}
		ps->a = a;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void STPop(ST* ps)//³öÕ»
{
	assert(!STEmpty(ps));
	ps->top--;
}

int STSize(ST* ps)//Õ»´óÐ¡
{
	assert(ps);
	return ps->top;
}

STDataType STTop(ST* ps)//Õ»¶¥ÔªËØ
{
	assert(ps);
	return ps->a[ps->top - 1];
}

void STDestroy(ST* ps)//Õ»Ïú»Ù
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
}

bool isValid(char* s)
{
	if (s == NULL)
	{
		return false;
	}
	int lenth = strlen(s);
	if (lenth % 2 != 0)
	{
		return false;
	}
	ST str;
	STInit(&str);
	int len = 0;
	char prev = 0;
	while (*(s + len) != '\0')
	{
		if (prev == '(' && *(s + len) == ')' ||
			prev == '{' && *(s + len) == '}' ||
			prev == '[' && *(s + len) == ']')
		{
			len++;
			STPop(&str);
		}
		else
		{
			STPush(&str, *(s + len));
			len++;
		}
		prev = STTop(&str);
	}
	if (str.top == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	char* s = "(({[]}))";
	if (isValid(s))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}