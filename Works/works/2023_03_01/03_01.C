#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);

struct ListNode
{
    int val;
    struct ListNode* next;
};

int main()
{
    struct ListNode s1;
    struct ListNode s2;
    struct ListNode s3;
    struct ListNode s4;
    struct ListNode s5;
    struct ListNode s6;
    s1.val = 1;
    s2.val = 1;
    s3.val = 1;
    s4.val = 1;
    s5.val = 1;
    s6.val = 1;
    s1.next = &s2;
    s2.next = &s3;
    s3.next = NULL;
    s4.next = &s5;
    s5.next = &s6;
    s1.next = NULL;
    struct ListNode* list1 = &s1;
    struct ListNode* list2 = &s2;
    struct ListNode* ret = mergeTwoLists(list1, list2);
    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* prev1 = list1;
    struct ListNode* prev2 = list2;
    if (prev1 || prev2)
    {
        if (prev1 == NULL)
        {
            return prev2;
        }
        return prev1;
    }
    struct ListNode* newhead = NULL;
    if (prev1->val < prev2)
    {
        newhead = prev1;
    }
    struct ListNode* cur1 = list1->next;
    struct ListNode* cur2 = list2->next;
    while (cur1 != NULL && cur2 != NULL)
    {
        if (prev1->val < prev2->val)
        {
            prev1->next = prev2;
            prev1 = cur1;
            cur1 = cur1->next;
        }
        else
        {
            prev2->next = prev1;
            prev2 = cur2;
            cur2 = cur2->next;
        }
    }
    if (cur1 == NULL)
    {
        prev1->next = prev2;
    }
    else
    {
        prev2->next = prev1;
    }
    return newhead;
}