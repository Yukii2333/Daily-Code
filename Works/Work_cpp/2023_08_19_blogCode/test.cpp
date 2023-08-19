#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

struct ListNode
{
	ListNode()
		:pre_(nullptr)
		,next_(nullptr)
		,val_(0)
	{}

	ListNode* pre_;
	ListNode* next_;
	int val_;
};

class List
{
public:

private:
	ListNode* list;
};