#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int num_;
    struct Node* next_;
}Node;

Node* ListAppend(Node* n, int x)
{
    if (n == NULL)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->next_ = newNode;
        newNode->num_ = x;
        return newNode;
    }
    else if (n->next_ == n)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->next_ = n;
        newNode->num_ = x;
        n->next_ = newNode;
        return n;
    }
    Node* cur = n;
    while (cur->next_ != n)
    {
        cur = cur->next_;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next_ = n;
    newNode->num_ = x;
    cur->next_ = newNode;
    return n;
}

Node* LoopPop(Node* n, int sit)
{
    Node* cur = n;
    Node* newLoop = NULL;
    while (cur->next_ != cur)
    {
        int pos = sit - 1;
        while (--pos)
        {
            cur = cur->next_;
        }
        Node* tmp = cur->next_;
        cur->next_ = tmp->next_;
        cur = cur->next_;
        newLoop = ListAppend(newLoop, tmp->num_);
        free(tmp);
    }
    newLoop = ListAppend(newLoop, cur->num_);
    free(cur);
    return newLoop;
}

void LoopPrint(Node* n)
{
    Node* cur = n;
    while (cur->next_ != n)
    {
        if (cur->num_ > 9)
        {
            printf("  ");
        }
        else
        {
            printf("   ");
        }
        printf("%d", cur->num_);
        cur = cur->next_;
    }
    if (cur->num_ > 9)
    {
        printf("  ");
    }
    else
    {
        printf("   ");
    }
    printf("%d", cur->num_);
}

int main()
{
    Node* loop = NULL;
    int sum, sit;
    scanf("%d", &sum);
    int i = 1;
    while (sum--)
    {
        loop = ListAppend(loop, i++);
    }

    while (scanf("%d", &sit) == 1)
    {
        loop = LoopPop(loop, sit);
    }
    LoopPrint(loop);
    return 0;
}