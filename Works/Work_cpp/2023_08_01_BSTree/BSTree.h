#pragma once
#include<iostream>

template<class K, class V>
struct BSTreeNode
{
	typedef BSTreeNode<K, V> Node;

	BSTreeNode(const K& key, const V& val)
		:_key(key)
		,_val(val)
		,_left(nullptr)
		,_right(nullptr)
	{}

	K _key;
	V _val;
	Node* _left;
	Node* _right;
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value);
	Node* Find(const K& key);
	bool Erase(const K& key);
	void _InOrder(Node* root);
	void InOrder();
private:
	Node* _root = nullptr;
};

template<class K, class V>
bool BSTree<K,V>::Insert(const K& key, const V& value)
{
	Node* newnode = new Node(key, value);
	if (_root == nullptr)
	{
		_root = newnode;
		return true;
	}
	Node* cur = _root;
	Node* prev = _root;
	while (cur)
	{
		prev = cur;
		if (newnode->_key == cur->_key)
		{
			return false;
		}
		else if (newnode->_key < cur->_key)
		{
			cur = cur->_left;
		}
		else
		{
			cur = cur->_right;
		}
	}
	if (newnode->_key < prev->_key)
	{
		prev->_left = newnode;
	}
	else
	{
		prev->_right = newnode;
	}
	return true;
}

template<class K,class V>
BSTreeNode<K,V>* BSTree<K,V>::Find(const K& key)
{
	Node* cur = _root;
	if (!cur)
	{
		return nullptr;
	}
	while (cur && cur->_key != key)
	{
		if (key < cur->_key)
		{
			cur = cur->_left;
		}
		else
		{
			cur = cur->_right;
		}
	}
	if (cur)
	{
		return cur;
	}
	return nullptr;
}

template<class K, class V>
void BSTree<K, V>::_InOrder(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	_InOrder(root->_left);
	std::cout << "key:" << root->_key << " valua:" << root->_val << std::endl;
	_InOrder(root->_right);
}
template<class K, class V>
void BSTree<K, V>::InOrder()
{
	_InOrder(_root);
}

template<class K, class V>
bool BSTree<K, V>::Erase(const K& key)
{
	if (_root == nullptr)
	{
		return false;
	}
	Node* cur = _root;
	Node* prev = _root;
	while (cur->_key != key)
	{
		prev = cur;
		if (key < cur->_key)
		{
			cur = cur->_left;
		}
		else
		{
			cur = cur->_right;
		}
	}
	//左右为空
	if (cur->_right == cur->_left)
	{
		if (prev == _root)
		{
			_root = nullptr;
		}
		delete cur;
		return true;
	}
	//右为空或者都存在
	if (cur->_left)
	{
		Node* _cur = cur->_left;
		prev = cur;
		while (_cur->_right)
		{
			prev = _cur;
			_cur = _cur->_right;
		}
		cur->_key = _cur->_key;
		cur->_val = _cur->_val;
		if (_cur == prev->_right)
		{
			prev->_right = _cur->_left;
		}
		else
		{
			prev->_left = _cur->_left;
		}
		delete _cur;
		return true;
	}
	//左为空
	else
	{
		Node* _cur = cur->_right;
		prev = cur;
		while (_cur->_left)
		{
			prev = _cur;
			_cur = _cur->_left;
		}
		cur->_key = _cur->_key;
		cur->_val = _cur->_val;
		if (_cur == prev->_right)
		{
			prev->_right = _cur->_right;
		}
		else
		{
			prev->_left = _cur->_right;
		}
		delete _cur;
		return true;
	}
}