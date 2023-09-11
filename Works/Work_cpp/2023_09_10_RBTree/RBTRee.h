#pragma once

#include<iostream>
#include<assert.h>

enum Colour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	typedef RBTreeNode<K, V> Node;

	std::pair<K, V> kv_;
	Colour cor_;
	RBTreeNode<K, V>* left_;
	RBTreeNode<K, V>* right_;
	RBTreeNode<K, V>* parent_;


	RBTreeNode(const std::pair<K, V> kv)
		:kv_(kv)
		,cor_(RED)
		,left_(nullptr)
		,right_(nullptr)
		,parent_(nullptr)
	{}
};

template<class K, class V>
class RBTree
{
public:
	typedef RBTreeNode<K, V> Node;

	//bool Insert(const std::pair<K, V>& kv)
	//{
	//	if (root_ == nullptr)
	//	{
	//		root_ = new Node(kv);
	//		root_->cor_ = BLACK;
	//		return true;
	//	}
	//	Node* cur = root_;
	//	Node* parent = root_;
	//	while (cur != nullptr)
	//	{
	//		parent = cur;
	//		if (kv.first < cur->kv_.first)
	//		{
	//			cur = cur->left_;
	//		}
	//		else if (kv.first > cur->kv_.first)
	//		{
	//			cur = cur->right_;
	//		}
	//		else
	//		{
	//			return false;
	//		}
	//	}

	//	cur = new Node(kv);
	//	cur->cor_ = RED;
	//	if (kv.first < parent->kv_.first)
	//	{
	//		parent->left_ = cur;
	//	}
	//	else
	//	{
	//		parent->right_ = cur;
	//	}
	//	cur->parent_ = parent;

	//	//颜色更新
	//	while(parent->parent_ && parent->cor_ != BLACK)
	//	{
	//		Node* grandparent = parent->parent_;
	//		Node* uncle = nullptr;
	//		if (grandparent)
	//		{
	//			if (grandparent->left_ == parent)
	//				uncle = grandparent->right_;

	//			else
	//				uncle = grandparent->left_;
	//		}

	//		if (uncle && uncle->cor_ == RED)
	//		{
	//			uncle->cor_ = parent->cor_ = BLACK;
	//			grandparent->cor_ = RED;
	//			cur = parent;
	//			parent = cur->parent_;
	//		}
	//		else if (uncle == nullptr || uncle->cor_ == BLACK)
	//		{
	//			if (parent == grandparent->right_)
	//			{
	//				//g
	//				//  p
	//				//    c
	//				if (cur == parent->right_)
	//				{
	//					RotateL(grandparent);
	//					parent->cor_ = BLACK;
	//					grandparent->cor_ = RED;
	//				}
	//				//g
	//				//  p
	//				//c
	//				else
	//				{
	//					RotateRL(grandparent);
	//					cur->cor_ = BLACK;
	//					grandparent->cor_ = RED;
	//				}
	//			}
	//			else
	//			{
	//				//    g
	//				//  p
	//				//c
	//				if (cur == parent->left_)
	//				{
	//					RotateR(grandparent);
	//					parent->cor_ = BLACK;
	//					grandparent->cor_ = RED;
	//				}
	//				//    g
	//				//  p
	//				//    c
	//				else
	//				{
	//					RotateLR(grandparent);
	//					cur->cor_ = BLACK;
	//					grandparent->cor_ = RED;
	//				}
	//			}
	//			break;
	//		}
	//	}
	//	if (parent->parent_ == nullptr)
	//	{
	//		parent->cor_ = BLACK;
	//	}
	//}

	bool Insert(std::pair<K,V> kv)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(kv);
			root_->cor_ = BLACK;
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
		cur->cor_ = RED;
		if (kv.first < parent->kv_.first)
		{
			parent->left_ = cur;
		}
		else
		{
			parent->right_ = cur;
		}
		cur->parent_ = parent;

		while (parent->parent_ && parent->cor_ == RED)
		{
			Node* grandparent = parent->parent_;
			
			if (parent == grandparent->left_)
			{
				Node* uncle = grandparent->right_;
				if (uncle && uncle->cor_ == RED)
				{
					uncle->cor_ = parent->cor_ = BLACK;
					grandparent->cor_ = RED;

					cur = parent;
					parent = grandparent;
				}
				else
				{
					if (cur == parent->left_)
					{
						RotateR(grandparent);
						parent->cor_ = BLACK;
						grandparent->cor_ = RED;
					}
					else
					{
						RotateL(parent);
						RotateR(grandparent);
						cur->cor_ = BLACK;
						grandparent->cor_ = RED;
					}
					break;
				}
			}
			else
			{
				Node* uncle = grandparent->left_;
				if (uncle && uncle->cor_ == RED)
				{
					uncle->cor_ = parent->cor_ = BLACK;
					grandparent->cor_ = RED;

					cur = parent;
					parent = grandparent;
				}
				else
				{
					if (cur == parent->right_)
					{
						RotateL(grandparent);
						parent->cor_ = BLACK;
						grandparent->cor_ = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(grandparent);
						cur->cor_ = BLACK;
						grandparent->cor_ = RED;
					}
					break;
				}
			}
		}
		root_->cor_= BLACK;
		return true;
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
	}
	void RotateRL(Node* parent)
	{
		Node* cur = parent->right_;
		Node* curLeft = cur->left_;
		RotateR(cur);
		RotateL(parent);
	}
	void RotateLR(Node* parent)
	{
		Node* cur = parent->left_;
		Node* curRight = cur->right_;
		RotateL(cur);
		RotateR(parent);
	}

	int Hight()
	{
		return Hight(root_);
	}

	bool IsRBTree()
	{
		return IsRBTree(root_);
	}

private:
	bool IsRBTree(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		if (root->cor_ != BLACK)
		{
			return false;
		}
		int benchmark = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->cor_ == BLACK)
				++benchmark;

			cur = cur->left_;
		}
		return CheakColour(root, 0, benchmark);
	}
	//benchmark为基准值，每条路径上的黑色节点个数相同
	bool CheakColour(Node* root, int blackNum, int benchmark)
	{
		if (root == nullptr)
		{
			if (blackNum != benchmark)
				return false;

			return true;
		}
		if (root->cor_ == BLACK)
		{
			++blackNum;
		}
		else if (root->cor_ == RED && root->parent_ && root->parent_->cor_ == RED)
		{
			std::cout << "出现连续红色节点！" << "cur_key:" << root->kv_.first << std::endl;
			return false;
		}
		return CheakColour(root->left_, blackNum, benchmark)
			&& CheakColour(root->right_, blackNum, benchmark);
	}
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



private:
	Node* root_ = nullptr;
};