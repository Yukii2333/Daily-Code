#pragma once

#include<iostream>
#include<vector>
#include<assert.h>

//适配不同类型的参数，对于一般整形可能只是走个形式
//但是负数之类的没有该仿函数将无法存储
template<class K>
struct DefaultHashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

//模板对string类型的特化
template<>
struct DefaultHashFunc<std::string>
{
	size_t operator()(const std::string& str)
	{
		size_t key = 0;
		for (auto e : str)
		{
			//BKDRhash算法，能极大程度降低字符串之间的冲突
			key *= 131;
			key += e;
		}
		return key;
	}
};

//哈希表
namespace hash_table
{
	enum STATE
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		std::pair<K, V> kv_;
		STATE state_ = EMPTY;
	};

	template<class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
		void swap(HashTable& tb)
		{
			size_ = tb.size_;
			std::swap(table_, tb.table_);
		}

	public:
		HashTable()
		{
			table_.resize(10);
		}

		bool Insert(const std::pair<K, V>& kv)
		{
			//线性探测
			HashFunc hf;
			size_t hash_i = hf(kv.first)%table_.size();
			if (Find(kv.first))
			{
				return false;
			}
			//找出表中从对应位置起，第一个元素为空或者删除位置
			while (table_[hash_i].state_ == EXIST)
			{
				++hash_i;
				hash_i %= table_.size();
			}
			table_[hash_i].kv_ = kv;
			table_[hash_i].state_ = EXIST;
			++size_;
			//根据负载因子扩容
			double factor = (double)size_ / (double)table_.size();
			if (factor >= 0.7)
			{
				HashTable<K,V,HashFunc> newTable;
				newTable.table_.resize(table_.size() * 2);
				for (size_t i = 0; i < table_.size(); ++i)
				{
					if (table_[i].state_ == EXIST)
					{
						newTable.Insert(table_[i].kv_);
					}
				}
				swap(newTable);
			}
			return true;
		}
		bool Find(const K& key)
		{
			HashFunc hf;
			rsize_t hash_i = hf(key) % table_.size();
			while (table_[hash_i].state_ == EXIST)
			{
				if (table_[hash_i].kv_.first == key)
				{
					return true;
				}
				else
				{
					++hash_i;
					hash_i %= table_.size();
				}
			}
			return false;
		}
		void Print()
		{
			for (auto& e : table_)
			{
				if (e.state_ == EXIST)
				{
					std::cout << e.kv_.first << " " << e.kv_.second << std::endl;
				}
			}
		}
		size_t Size()
		{
			return size_;
		}
		bool Erase(const K& key)
		{
			HashFunc hf;
			rsize_t hash_i = hf(key) % table_.size();
			while (table_[hash_i].state_ == EXIST)
			{
				if (table_[hash_i].kv_.first == key)
				{
					table_[hash_i].state_ = DELETE;
					--size_;
					return true;
				}
				else
				{
					++hash_i;
					hash_i %= table_.size();
				}
			}
			return true;
		}

	private:
		std::vector<HashData<K, V>> table_;
		rsize_t size_ = 0;
	};

}

//开散列哈希桶
namespace hash_bucket
{
	//前置声明
	//由于iterator内部会使用哈希表内的成员，因而需要前置声明
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class T>
	struct DataNode
	{
		T data_;
		DataNode<T>* next_;

		DataNode(const T& data) :data_(data), next_(nullptr) {};
	};



	//迭代器封装
	//template<class K, class T, class KeyOfT, class HashFunc>
	template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
	struct HashTableIterator
	{
		typedef HashTableIterator<K, T, Ptr, Ref, KeyOfT, HashFunc> Self;
		typedef HashTableIterator<K, T, T*, T&, KeyOfT, HashFunc> Iterator;
		typedef HashTable<K, T, KeyOfT, HashFunc> HashTable;
		typedef DataNode<T> Node;

		//节点的指针+哈希表的指针
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
		//遵循从上往下从左往右的原则
		Self& operator++()
		{
			//当前桶还未完
			if (node_->next_)
			{
				node_ = node_->next_;
			}
			//寻找下一个桶
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
				//后面无元素
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
			//当前位置为桶的第一个位置
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
				//前面无元素
				node_ = nullptr;
			}
			//当前位置不为桶的第一个位置
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
		//友元声明
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
			//注意要传this指针
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
		//先开10个空间使用，便于操作
		HashTable()
		{
			table_.resize(10, nullptr);
		}
		//由于Node是自定义类型，new出来之后，需要自行delete
		//避免内存泄漏
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
			//KeyOfT与HashFunc的仿函数
			HashFunc hf;
			KeyOfT kot;
			//不能插入已有数据==>去重
			iterator it = Find(kot(data));
			if (it != end())
			{
				return std::make_pair(it, false);
			}
			//用size取模而不是capacity
			//[]不允许访问大于size小于capacity之间的位置
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

			//扩容
			//负载因子，一般控制在低于0,7~0.8
			//负载因子越大，空间利用率越大，查找效率越低
			//负载因子越小，空间利用率越低，查找效率越高
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
			//对应桶在vector中的下标
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
			--size_;
			return true;
		}
		size_t size()
		{
			return size;
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
		//size_记录的是有效数据个数
		std::vector<Node*> table_;
		size_t size_ = 0;
	};
}