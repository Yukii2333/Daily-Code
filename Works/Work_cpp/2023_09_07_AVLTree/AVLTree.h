#pragma once


#include<iostream>

template<class K, class V>
struct AVLTreeNode
{
	typedef AVLTreeNode<K, V> Node;

	pair<K, V> kv_;
	AVLTreeNode<K, V>* left_;
	AVLTreeNode<K, V>* right_;
	AVLTreeNode<K, V>* parent_;
	//平衡因子
	int bf_;

	AVLTreeNode(const pair<K, V> kv)
		:kv_(kv)
		,left_(nullptr)
		,right_(nullptr)
		,parent_(nullptr)
		,bf_(0)
	{}
	
};

template<class K, class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> Node;

	bool Insert(const pair<K, V>& kv)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(kv);
			return true;
		}
		Node* cur = root_;
		Node* parent = root_;
		while (cur != nullptr)
		{
			parent = cur;
			if (kv.first < cur->kv_.first)
			{
				cur = cur->left_;
			}
			else if (kv.first > cur->kv_.first)
			{
				cur = cur->right_;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (kv.first < parent->kv_.first)
		{
			parent->left_ = cur;
		}
		else
		{
			parent->right_ = cur;
		}
		cur->parent_ = parent;

		//更新平衡因子
		while (parent != nullptr)
		{
			if (cur == parent->left_)
			{
				parent->bf_--;
			}
			else
			{
				parent->bf_++;
			}

			if (parent->bf_ == 0)
			{
				break;
			}
			else if (abs(parent->bf_) == 1)
			{
				cur = parent;
				parent = parent->parent_;
			}
			else if (abs(parent->bf_) == 2)
			{
				if (parent->bf_ == 2 && cur->bf_ == 1)
				{
					RotateL(parent);
				}
				else if (parent->bf_ == -2 && cur->bf_ == -1)
				{
					RotateR(parent);
				}
				else if (parent->bf_ == 2 && cur->bf_ == -1)
				{
					RotateRL(parent);
				}
				else if (parent->bf_ == -2 && cur->bf_ == 1)
				{
					RotateLR(parent);
				}
				break;
			}
		}
		

	}

	//旋转
	void RotateL(Node* parent)
	{
		Node* cur = parent->right_;
		Node* curLeft = cur->left_;
		
		cur->left_ = parent;
		parent->right_ = curLeft;
		

		if (curLeft)
		{
			curLeft->parent_ = parent;
		}

		Node* pParent = parent->parent_;
		parent->parent_ = cur;
		cur->parent_ = pParent;

		if (pParent)
		{
			if (pParent->left_ == parent)
			{
				pParent->left_ = cur;
			}
			else
			{
				pParent->right_ = cur;
			}
		}
		else
		{
			root_ = cur;
		}

		parent->bf_ = cur->bf_ = 0;
	}

	void RotateR(Node* parent)
	{
		Node* cur = parent->left_;
		Node* curRight = cur->right_;

		cur->right_ = parent;
		parent->left_ = curRight;

		if (curRight)
		{
			curRight->parent_ = parent;
		}

		Node* pParent = parent->parent_;
		parent->parent_ = cur;
		cur->parent_ = pParent;
		if (pParent)
		{
			if (pParent->left_ == parent)
			{
				pParent->left_ = cur;
			}
			else
			{
				pParent->right_ = cur;
			}
		}
		else
		{
			root_ = cur;
		}

		parent->bf_ = cur->bf_ = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* cur = parent->right_;
		Node* curLeft = cur->left_;
		int bf = curLeft->bf_;
		RotateR(cur);
		RotateL(parent);
		if (bf == -1)
		{
			cur->bf_ = 1;
			parent->bf_ = 0;
			curLeft->bf_ = 0;
		}
		else if (bf == 1)
		{
			cur->bf_ = 0;
			parent->bf_ = -1;
			curLeft->bf_ = 0;
		}
		else if (bf == 0)
		{
			cur->bf_ = 0;
			parent->bf_ = 0;
			curLeft->bf_ = 0;
		}
	}

	void RotateLR(Node* parent)
	{
		Node* cur = parent->left_;
		Node* curRight = cur->right_;
		int bf = curRight->bf_;
		RotateL(cur);
		RotateR(parent);
		if (bf == -1)
		{
			cur->bf_ = 0;
			parent->bf_ = 1;
			curRight->bf_ = 0;
		}
		else if (bf == 1)
		{
			cur->bf_ = -1;
			parent->bf_ = 0;
			curRight->bf_ = 0;
		}
		else if (bf == 0)
		{
			cur->bf_ = 0;
			parent->bf_ = 0;
			curRight->bf_ = 0;
		}
	}

	int Hight()
	{
		return Hight(root_);
	}
	bool IsBalance()
	{
		return IsBalance(root_);
	}

private:
	//求高度
	int Hight(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int leftHight = Hight(root->left_);
		int rightHight = Hight(root->right_);
		return leftHight > rightHight ? leftHight + 1 : rightHight + 1;
	}
	//判断是否是AVL树
	bool IsBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		int leftHight = Hight(root->left_);
		int rightHight = Hight(root->right_);
		if ((rightHight - leftHight) != root->bf_)
		{
			std::cout << "平衡因子异常：" << "key:" << root->kv_.first << std::endl;
			return false;
		}
		return IsBalance(root->left_) && IsBalance(root->right_);
	}

private:
	Node* root_ = nullptr;
};