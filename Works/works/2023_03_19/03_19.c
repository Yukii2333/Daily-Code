#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef char STDataType;

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


bool STEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;
}

void STInit(ST* ps)
{
    assert(ps);
    STDataType* tmp = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (tmp == NULL)
    {
        perror("malloc fail");
        return;
    }
    ps->a = tmp;
    ps->capacity = 4;
    ps->top = 0;
    printf("%p\n", &ps->a);
}

void STPush(ST* ps, STDataType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
        if (tmp == NULL)
        {
            perror("malloc fail");
            return;
        }
        ps->a = tmp;
        ps->capacity = sizeof(STDataType) * ps->capacity * 2;
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
    return ps->a[ps->top - 1];
}

void STDestroy(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = 0;
}

bool isValid(char* s) {
    if (s == NULL)
    {
        return false;
    }
    ST stack;
    STInit(&stack);
    while (*s)
    {
        if (*s == '[' || *s == '{' || *s == '(')
        {
            STPush(&stack, *s);
        }
        else
        {
            if (STEmpty(&stack))
            {
                STDestroy(&stack);
                return false;
            }
            char top = STTop(&stack);
            STPop(&stack);
            if (top == '(' && *s != ')' ||
                top == '[' && *s != ']' ||
                top == '{' && *s != '}')
            {
                STDestroy(&stack);
                return false;
            }
        }
        ++s;
    }
    if (!STEmpty(&stack))
    {
        STDestroy(&stack);
        return false;
    }
    STDestroy(&stack);
    return true;
}

int main()
{
    char* s = "[[[[[[[[[[[[[[[[[[[";
    bool ret = isValid(s);
    printf("%d", ret);
    return 0;
}