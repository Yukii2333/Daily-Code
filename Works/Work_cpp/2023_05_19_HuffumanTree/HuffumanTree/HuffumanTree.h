#pragma once

#include <deque>
#include<algorithm>
#include<iostream>

using namespace std;

//哈夫曼树节点
//info_表示信息（暂且定为char）
//key_表示权重
//left_\right_\parent_ 分别是左孩子、右孩子以及双亲节点
template<typename T>
struct HTNode
{
	//构造函数+初始化列表
	HTNode<T>(T info, int key, HTNode<T>* left = nullptr,
			  HTNode<T>* right = nullptr, HTNode<T>* parent = nullptr)
		:info_(info)
		,key_(key)
		,left_(left)
		,right_(right)
		,parent_(parent)
	{}
	~HTNode<T>()
	{}


	T info_;
	int key_;
	HTNode<T>* left_;
	HTNode<T>* right_;
	HTNode<T>* parent_;
};


//哈夫曼树
template<typename T>
class HFTree
{
public:
	HFTree<T>(int size = 0, HTNode<T>* root = nullptr)
		:size_(size)
		,root_(root)
	{}
	~HFTree<T>()
	{
		root_ = nullptr;
	}

	//构建哈夫曼树
	void CreatTree(T* info, int* key, int size);

	//求WPL
	inline int GetWPL()
	{
		return GetWPL(root_,0);
	}
	int GetWPL(HTNode<T>* root, int Depth);

	//前序输出哈夫曼树
	inline void Preorder()
	{
		Preorder(root_);
	}
	void Preorder(HTNode<T>* root);

	//获取哈夫曼编码
	inline void HuffumanCode()
	{
		int* arr = new int[size_];
		int Depth = 0;
		HuffumanCode(root_, arr, Depth);
		delete[] arr;
	}
	void HuffumanCode(HTNode<T>* root, int* a, int Depth);


	//销毁哈夫曼树
	inline void Destroy()
	{
		Destroy(root_);
	}
	void Destroy(HTNode<T>* root);


private:
	//size_用于存储节点个数
	//root_用于表示哈夫曼树根节点
	//forest_用于表示节点形成的森林，用于构建哈夫曼树，借助双端队列
	int size_;
	HTNode<T>* root_;
	deque<HTNode<T>*> forest_;
};

//比较函数，在排序中作为依据
template<typename T>
bool Comp(HTNode<T>* node1, HTNode<T>* node2){return (node1->key_ < node2->key_);}

//构建哈夫曼树
template<typename T>
void HFTree<T>::CreatTree(T* info, int* key, int size)
{
	//创建节点，先将每一个都作为森林
	for (int i = 0; i < size; ++i)
	{
		HTNode<T>* node = new HTNode<T>(info[i],key[i]);
		forest_.push_back(node);
	}

	for (int i = 0; i < size - 1; ++i)
	{
		//库函数，排序，依次顺序是： 起始位置、结束位置以及排序方式
		//每次排序完成后，队列顺序就以权重递增的顺序分布
		sort(forest_.begin(), forest_.end(), Comp<T>);
		//没有数据的节点默认信息存为 \n
		HTNode<T>* node = new HTNode<T>('\n', forest_[0]->key_ + forest_[1]->key_, forest_[0], forest_[1]);
		//设置双亲节点
		forest_[0]->parent_ = forest_[1]->parent_ = node;
		//尾插新节点，然后对以组合的节点进行出队
		forest_.push_back(node);
		forest_.pop_front();
		forest_.pop_front();
	}

	//记录节点个数
	size_ = size;
	root_ = forest_.front();
	//清理双端队列（并不是销毁）
	forest_.clear();
}


//计算WPL
template<typename T>
int HFTree<T>::GetWPL(HTNode<T>* root, int Depth)
{
	if (root == nullptr)
	{
		return 0;
	}
	if (root->left_ == nullptr && root->right_ == nullptr)
	{
		return root->key_ * Depth;
	}
	int left = GetWPL(root->left_, Depth + 1);
	int right = GetWPL(root->right_, Depth + 1);
	return left + right;
}


//前序输出哈夫曼树
template<typename T>
void HFTree<T>::Preorder(HTNode<T>*root)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->info_ != '\n')
	{
		cout <<"info: " << root->info_ << " key: " << root->key_ << endl;
	}
	Preorder(root->left_);
	Preorder(root->right_);
}

//获取哈夫曼编码
template<typename T>
void HFTree<T>::HuffumanCode(HTNode<T>* root, int* a, int Depth)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->parent_ != nullptr)
	{
		if (root == root->parent_->left_)
		{
			a[Depth - 1] = 0;
		}
		else
		{
			a[Depth - 1] = 1;
		}
		if (root->info_ != '\n')
		{
			cout << "info: " << root->info_ << " key: " << root->key_ << " Code: ";
			for (int i = 0; i < Depth; ++i)
			{
				cout << a[i];
			}
			cout << endl;
		}
	}
	HuffumanCode(root->left_, a, Depth + 1);
	HuffumanCode(root->right_, a, Depth + 1);
}


//销毁哈夫曼树
template<typename T>
void HFTree<T>::Destroy(HTNode<T>* root)
{
	if (root == nullptr)
		return;
	Destroy(root->left_);
	Destroy(root->right_);
	delete root;
}

