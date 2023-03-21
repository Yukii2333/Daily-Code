#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

void STInit(ST* ps)
{
	STDataType* a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->a = a;
	ps->capacity = 4;
	ps->top = 0;
}

void STPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* a = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
		if (a == NULL)
		{
			perror("malloc fail");
			return;
		}
		ps->a = a;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void STPop(ST* ps)
{
	assert(!STEmpty(ps));
	ps->top--;
}

int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

STDataType STTop(ST* ps)
{
	assert(ps);
	return ps->a[ps->top-1];
}

void STDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
}