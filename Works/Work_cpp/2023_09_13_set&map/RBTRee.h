#pragma once

#include<iostream>
#include<assert.h>

enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{

	T data_;
	Colour cor_;
	RBTreeNode<T>* left_;
	RBTreeNode<T>* right_;
	RBTreeNode<T>* parent_;


	RBTreeNode(const T& data)
		:data_(data)
		,cor_(RED)
		,left_(nullptr)
		,right_(nullptr)
		,parent_(nullptr)
	{}
};

template<class T>
struct _RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef _RBTreeIterator<T> Self;

	Node* node_;

	_RBTreeIterator(Node* node) :node_(node) {}

	T& operator*()
	{
		return node_->data_;
	}
	T* operator->()
	{
		return &(node_->date_);
	}
	bool operator!=(const Self & s)
	{
		return node_ != s.node_;
	}
	Self& operator++()
	{
		if (node_->right_)
		{
			//右树存在时，下一个节点就是右树的最左节点
			Node* nextNode = node_->right_;
			while (nextNode->left_)
			{
				nextNode = nextNode->left_;
			}
			node_ = nextNode;
		}
		else
		{
			//右子树为空的情况下，下一个节点是cur为parent的左孩子时的parent
			Node* cur = node_;
			Node* parent = cur->parent_;
			while (parent)
			{
				if (cur == parent->left_)
				{
					break;
				}

				else
				{
					cur = parent;
					parent = cur->parent_;
				}
			}
			node_ = parent;
		}
		return *this;
	}
	Self& operator--()
	{
		if (node_->left_)
		{
			//左子树存在时，上一个节点就是左子树的最右节点
			Node* nextNode = node_;
			while (nextNode->right_)
			{
				nextNode = nextNode->right_;
			}
			node_ = nextNode;
		}
		else
		{
			//左子树为空的情况下，下一个节点是cur为parent的右孩子时的parent
			Node* cur = node_;
			Node* parent = cur->parent_;
			while (parent)
			{
				if (cur == parent->right_)
				{
					break;
				}
				else
				{
					cur = parent;
					parent = cur->parent_;
				}
			}
		}
	}
};

template<class T>
struct _RBTreeReverseIterator
{
	typedef RBTreeNode<T> Node;
	typedef _RBTreeReverseIterator<T> Self;
	typedef _RBTreeIterator<T> Iterator

	Iterator it_;

	T& operator*()
	{
		return *(it_);
	}
	T* operator->()
	{
		return &(operator*());
	}
	bool operator!=() 
	{

	}

};

//////////////////////////////////////////////////////////


template<class K, class T, class keyOfT>
class RBTree
{
public:
	typedef RBTreeNode<T> Node;
	typedef _RBTreeIterator<T> iterator;
	typedef _RBTreeIterator<const T> const_iterator;

	iterator begin()
	{
		Node* farLeft = root_;
		while (farLeft && farLeft->left_)
		{
			farLeft = farLeft->left_;
		}
		return iterator(farLeft);
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	const_iterator begin() const
	{
		Node* farLeft = root_;
		while (farLeft && farLeft->left_)
		{
			farLeft = farLeft->left_;
		}
		return iterator(farLeft);
	}
	const_iterator end() const
	{
		return iterator(nullptr);
	}


	Node* Find(const K& key) const
	{
		Node* cur = root_;
		keyOfT kot;
		while (cur)
		{
			if (kot(cur->data_) > key)
			{
				cur = cur->left_;
			}
			else if(kot(cur->data_) < key)
			{
				cur = cur->right_;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(data);
			root_->cor_ = BLACK;

			++size_;
			return true;
		}
		Node* cur = root_;
		Node* parent = root_;
		keyOfT kot;
		while (cur != nullptr)
		{
			parent = cur;
			if (kot(cur->data_) > kot(data))
			{
				cur = cur->left_;
			}
			else if (kot(cur->data_) < kot(data))
			{
				cur = cur->right_;
			}
			else
			{
				return false;
			}
		}

		++size_;

		cur = new Node(data);
		cur->cor_ = RED;
		if (kot(data) < kot(parent->data_))
		{
			parent->left_ = cur;
		}
		else
		{
			parent->right_ = cur;
		}
		cur->parent_ = parent;

		while (parent && parent->cor_ == RED)
		{
			Node* grandparent = parent->parent_;
			
			if (parent == grandparent->left_)
			{
				Node* uncle = grandparent->right_;
				if (uncle && uncle->cor_ == RED)
				{
					uncle->cor_ = parent->cor_ = BLACK;
					grandparent->cor_ = RED;
					cur = grandparent;
					parent = cur->parent_;
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

					cur = grandparent;
					parent = cur->parent_;
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
	int Hight()
	{
		return Hight(root_);
	}

	bool IsBalance()
	{
		return IsBalance(root_);
	}

private:
	bool IsBalance(Node* root)
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
public:
	size_t size_ = 0;
};