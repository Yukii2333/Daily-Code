#pragma once

#include <deque>
#include<algorithm>
#include<iostream>

using namespace std;

//���������ڵ�
//info_��ʾ��Ϣ�����Ҷ�Ϊchar��
//key_��ʾȨ��
//left_\right_\parent_ �ֱ������ӡ��Һ����Լ�˫�׽ڵ�
template<typename T>
struct HTNode
{
	//���캯��+��ʼ���б�
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


//��������
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

	//������������
	void CreatTree(T* info, int* key, int size);

	//��WPL
	inline int GetWPL()
	{
		return GetWPL(root_,0);
	}
	int GetWPL(HTNode<T>* root, int Depth);

	//ǰ�������������
	inline void Preorder()
	{
		Preorder(root_);
	}
	void Preorder(HTNode<T>* root);

	//��ȡ����������
	inline void HuffumanCode()
	{
		int* arr = new int[size_];
		int Depth = 0;
		HuffumanCode(root_, arr, Depth);
		delete[] arr;
	}
	void HuffumanCode(HTNode<T>* root, int* a, int Depth);


	//���ٹ�������
	inline void Destroy()
	{
		Destroy(root_);
	}
	void Destroy(HTNode<T>* root);


private:
	//size_���ڴ洢�ڵ����
	//root_���ڱ�ʾ�����������ڵ�
	//forest_���ڱ�ʾ�ڵ��γɵ�ɭ�֣����ڹ�����������������˫�˶���
	int size_;
	HTNode<T>* root_;
	deque<HTNode<T>*> forest_;
};

//�ȽϺ���������������Ϊ����
template<typename T>
bool Comp(HTNode<T>* node1, HTNode<T>* node2){return (node1->key_ < node2->key_);}

//������������
template<typename T>
void HFTree<T>::CreatTree(T* info, int* key, int size)
{
	//�����ڵ㣬�Ƚ�ÿһ������Ϊɭ��
	for (int i = 0; i < size; ++i)
	{
		HTNode<T>* node = new HTNode<T>(info[i],key[i]);
		forest_.push_back(node);
	}

	for (int i = 0; i < size - 1; ++i)
	{
		//�⺯������������˳���ǣ� ��ʼλ�á�����λ���Լ�����ʽ
		//ÿ��������ɺ󣬶���˳�����Ȩ�ص�����˳��ֲ�
		sort(forest_.begin(), forest_.end(), Comp<T>);
		//û�����ݵĽڵ�Ĭ����Ϣ��Ϊ \n
		HTNode<T>* node = new HTNode<T>('\n', forest_[0]->key_ + forest_[1]->key_, forest_[0], forest_[1]);
		//����˫�׽ڵ�
		forest_[0]->parent_ = forest_[1]->parent_ = node;
		//β���½ڵ㣬Ȼ�������ϵĽڵ���г���
		forest_.push_back(node);
		forest_.pop_front();
		forest_.pop_front();
	}

	//��¼�ڵ����
	size_ = size;
	root_ = forest_.front();
	//����˫�˶��У����������٣�
	forest_.clear();
}


//����WPL
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


//ǰ�������������
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

//��ȡ����������
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


//���ٹ�������
template<typename T>
void HFTree<T>::Destroy(HTNode<T>* root)
{
	if (root == nullptr)
		return;
	Destroy(root->left_);
	Destroy(root->right_);
	delete root;
}

