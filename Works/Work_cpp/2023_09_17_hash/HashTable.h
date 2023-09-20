#pragma once

#include<iostream>
#include<vector>
#include<assert.h>

namespace hash_bucket
{
	//ǰ������
	//����iterator�ڲ���ʹ�ù�ϣ���ڵĳ�Ա�������Ҫǰ������
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class T>
	struct DataNode
	{
		T data_;
		DataNode<T>* next_;

		DataNode(const T& data) :data_(data), next_(nullptr) {};
	};

	//���䲻ͬ���͵Ĳ���������һ�����ο���ֻ���߸���ʽ
	//���Ǹ���֮���û�и÷º������޷��洢
	template<class K>
	struct DefaultHashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	//ģ���string���͵��ػ�
	template<>
	struct DefaultHashFunc<std::string>
	{
		size_t operator()(const std::string& str)
		{
			size_t key = 0;
			for (auto e : str)
			{
				//BKDRhash�㷨���ܼ���̶Ƚ����ַ���֮��ĳ�ͻ
				key *= 131;
				key += e;
			}
			return key;
		}
	};

	//��������װ
	//template<class K, class T, class KeyOfT, class HashFunc>
	template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
	struct HashTableIterator
	{
		typedef HashTableIterator<K, T, Ptr, Ref, KeyOfT, HashFunc> Self;
		typedef HashTableIterator<K, T, T*, T&, KeyOfT, HashFunc> Iterator;
		typedef HashTable<K, T, KeyOfT, HashFunc> HashTable;
		typedef DataNode<T> Node;

		//�ڵ��ָ��+��ϣ���ָ��
		Node* node_;
		const HashTable* ptb_;

		HashTableIterator(Node* node, const HashTable* ptb) :node_(node), ptb_(ptb) {};
		HashTableIterator(const Iterator& it) :node_(it.node_), ptb_(it.ptb_) {};

		Ref operator*()
		{
			return node_->data_;
		}
		Ptr operator->()
		{
			return &node_->data_;
		}
		//��ѭ�������´������ҵ�ԭ��
		Self& operator++()
		{
			//��ǰͰ��δ��
			if (node_->next_)
			{
				node_ = node_->next_;
			}
			//Ѱ����һ��Ͱ
			else
			{
				KeyOfT kot;
				HashFunc hf;
				size_t key = hf(kot(node_->data_));
				size_t hash_i = key % ptb_->table_.size();
				++hash_i;
				while (hash_i < ptb_->table_.size())
				{
					if (ptb_->table_[hash_i])
					{
						node_ = ptb_->table_[hash_i];
						return *this;
					}
					else
					{
						++hash_i;
					}
				}
				//������Ԫ��
				node_ = nullptr;
			}
			return *this;
		}
		Self& operator--()
		{
			KeyOfT kot;
			HashFunc hf;
			size_t key = hf(kot(node_->data_));
			size_t hash_i = key % ptb_->table_.size();
			//��ǰλ��ΪͰ�ĵ�һ��λ��
			if (ptb_->table_[hash_i] == node_)
			{
				--hash_i;
				while (hash_i >= 0)
				{
					if (ptb_->table_[hash_i])
					{
						Node* cur = ptb_->table_[hash_i];
						while (cur->next_)
						{
							cur = cur->next_;
						}
						node_ = cur;
						return *this;
					}
					else
					{
						--hash_i;
					}
				}
				//ǰ����Ԫ��
				node_ = nullptr;
			}
			//��ǰλ�ò�ΪͰ�ĵ�һ��λ��
			else
			{
				Node* prev = ptb_->table_[hash_i];
				while (prev->next_ != node_)
				{
					prev = prev->next_;
				}
				node_ = prev;
				return *this;
			}
			return *this;
		}
		bool operator!=(const Self& it)
		{
			return node_ != it.node_;
		}
		bool operator==(const Self& it)
		{
			return node_ == it.node_;
		}
	};

	template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
		//��Ԫ����
		template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
		friend struct HashTableIterator;

		typedef DataNode<T> Node;
	public:
		typedef HashTableIterator<K, T, T*, T&, KeyOfT, HashFunc> iterator;
		typedef HashTableIterator<K, T, const T*, const T&, KeyOfT, HashFunc> const_iterator;

		iterator begin()
		{
			Node* cur = nullptr;
			for (size_t i = 0; i < table_.size(); ++i)
			{
				cur = table_[i];
				if (cur)
				{
					break;
				}
			}
			//ע��Ҫ��thisָ��
			return iterator(cur, this);
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		const_iterator begin() const
		{
			Node* cur = nullptr;
			for (size_t i = 0; i < table_.size(); ++i)
			{
				cur = table_[i];
				if (cur)
				{
					break;
				}
			}
			return const_iterator(cur, this);
		}
		const_iterator end() const
		{
			return const_iterator(nullptr, this);
		}

	public:
		//�ȿ�10���ռ�ʹ�ã����ڲ���
		HashTable()
		{
			table_.resize(10, nullptr);
		}
		//����Node���Զ������ͣ�new����֮����Ҫ����delete
		//�����ڴ�й©
		~HashTable()
		{
			Node* cur = nullptr;
			for (size_t i = 0; i < table_.size(); ++i)
			{
				cur = table_[i];
				while (cur)
				{
					Node* tmp = cur->next_;
					delete cur;
					cur = tmp;
				}
			}
		}
		std::pair<iterator,bool> Insert(const T& data)
		{
			//KeyOfT��HashFunc�ķº���
			HashFunc hf;
			KeyOfT kot;
			//���ܲ�����������==>ȥ��
			iterator it = Find(kot(data));
			if (it != end())
			{
				return std::make_pair(it, false);
			}
			//��sizeȡģ������capacity
			//[]��������ʴ���sizeС��capacity֮���λ��
			size_t hash_i = hf(kot(data)) % table_.size();
			Node* newnode = new Node(data);
			newnode->next_ = table_[hash_i];
			table_[hash_i] = newnode;
			++size_;

			//if (table_[hash_i] == nullptr)
			//{
			//	table_[hash_i] = new Node(data);
			//	++size_;
			//}
			//else
			//{
			//	Node* newnode = new Node(data);
			//	newnode->next_ = table_[hash_i];
			//	table_[hash_i] = newnode;
			//	++size_;
			//}

			//�������ӣ�һ������ڵ���0,7~0.8
			//��������Խ�󣬿ռ�������Խ�󣬲���Ч��Խ��
			//��������ԽС���ռ�������Խ�ͣ�����Ч��Խ��
			double factor = (double)size_ / (double)table_.size();
			if (factor >= 0.7)
			{
				std::vector<Node*> newTable;
				newTable.resize(table_.size() * 2, nullptr);
				Node* cur = nullptr;
				for (size_t i = 0; i < table_.size(); ++i)
				{
					cur = table_[i];
					while (cur)
					{
						Node* tmp = cur->next_;
						hash_i = hf(kot(cur->data_)) % newTable.size();
						cur->next_ = newTable[hash_i];
						newTable[hash_i] = cur;
						//if (newTable[hash_i] == nullptr)
						//{
						//	newTable[hash_i] = cur;
						//	cur->next_ = nullptr;
						//}
						//else
						//{
						//	newnode->next_ = newTable[hash_i];
						//	newTable[hash_i] = newnode;
						//}
						cur = tmp;
					}
				}
				std::swap(table_, newTable);

			}
			return std::make_pair(iterator(newnode, this), true);
		}
		iterator Find(const K& key)
		{
			KeyOfT kot;
			HashFunc hf;
			//��ӦͰ��vector�е��±�
			size_t hash_i = hf(key) % table_.size();
			Node* cur = table_[hash_i];
			while (cur)
			{
				if (kot(cur->data_) == key)
				{
					return iterator(cur,this);
				}
				cur = cur->next_;
			}
			return iterator(nullptr, this);
		}
		bool Erase(const T& data)
		{
			KeyOfT kot;
			HashFunc hf;
			int key = hf(kot(data));
			Node* cur = table_[key % table_.size()];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->data_) == key)
				{
					break;
				}
				prev = cur;
				cur = cur->next_;
			}
			if (cur == nullptr)
			{
				return false;
			}
			if (prev == nullptr)
			{
				table_[key % table_.size()] = cur->next_;
				delete cur;
			}
			else
			{
				prev->next_ = cur->next_;
				delete cur;
			}
			Print();
			return true;
		}
		void Print()
		{
			KeyOfT kot;
			HashFunc hf;
			Node* cur = nullptr;
			for (size_t i = 0; i < table_.size(); ++i)
			{
				cur = table_[i];
				while (cur)
				{
					Node* tmp = cur->next_;
					std::cout << hf(kot(cur->data_)) << "->";
					cur = tmp;
				}
				std::cout << "NULL" << std::endl;
			}
			std::cout << std::endl;
		}
	public:

	private:
		//size_��¼������Ч���ݸ���
		size_t size_ = 0;
		std::vector<Node*> table_;
	};
}