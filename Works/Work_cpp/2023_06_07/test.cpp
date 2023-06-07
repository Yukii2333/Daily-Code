#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    int data_;
    struct TreeNode* left_;
    struct TreeNode* right_;
}TNode;

typedef struct BinerySearchTree
{
    TNode* root_;
}BST;

void TreeInit(BST* t)
{
    t->root_ = NULL;
}

void TreeAppend(BST* t, int x)
{
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    if (newNode == NULL)
    {
        perror("malloc fail!");
        return;
    }
    newNode->data_ = x;
    newNode->right_ = NULL;
    newNode->left_ = NULL;
    if (t->root_ == NULL)
    {
        t->root_ = newNode;
        return;
    }
    TNode* cur = t->root_;
    TNode* prv = NULL;
    while (cur)
    {
        prv = cur;
        if (cur->data_ >= x)
        {
            cur = cur->left_;
        }
        else
        {
            cur = cur->right_;
        }
    }
    if (prv->data_ >= x)
    {
        prv->left_ = newNode;
    }
    else
    {
        prv->right_ = newNode;
    }
}

void PreOrder_(TNode* root)
{
    printf("%d ", root->data_);
    PreOrder_(root->left_);
    PreOrder_(root->right_);
}
void PreOrder(BST* t)
{
    TNode* cur = t->root_;
    PreOrder_(cur);
}

void TreeDestroy(TNode* root)
{
    TreeDestroy(root->left_);
    TreeDestroy(root->right_);
    free(root);
}
void TreeClear(BST* t)
{
    TreeDestroy(t->root_);
    t->root_ = NULL;
}

int main()
{
    int n = 1;
    BST t;
    TreeInit(&t);
    while (n)
    {
        scanf("%d", &n);
        TreeAppend(&t, n);
    }
    PreOrder(&t);
    TreeClear(&t);
    return 0;
}