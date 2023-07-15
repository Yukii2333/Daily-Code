#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 
#include <stdlib.h> 

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};
typedef struct node* Position;
typedef struct node* List;

List createList();
void insertNode(List L, int x);
void deleteNode(List L, Position p);
void printList(List L);
void game(List L, int m, int n);

int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);
    List L = createList();
    for (int i = 1; i <= m; i++)
    {
        insertNode(L, i);
    }
    game(L, m, n);
    return 0;
}
void game(List L, int m, int n)
{
    Position p = L->next;
    while (m != 0)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            p = p->next;
            if (p == L)
            {
                p = p->next;
            }
        }
        printf("%4d", p->data);
        deleteNode(L, p);
        m--;
    }
}
List createList()
{
    List head = (node*)malloc(sizeof(struct node));
    head->next = head->prev = head;
    return head;
}
void insertNode(List L, int x)
{
    Position t = (node*)malloc(sizeof(struct node));
    t->data = x;
    //t->prev->next = t;
    t->next = L;
    t->prev = L->prev;

    L->prev->next = t;

    L->prev = t;
}
void deleteNode(List L, Position p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}
void printList(List L)
{
    Position p = L->next;
    while (p != L)
    {
        printf("%4d", p->data);
        p = p->next;
    }
}