#pragma once

#include<iostream>
#include"HashTable.h"

namespace MySTL
{
	template<class K>
	class unordered_set
	{
		struct KeyOfSet
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, K, KeyOfSet>::iterator iterator;

		iterator begin()
		{
			return tb_.begin();
		}
		iterator end()
		{
			return tb_.end();
		}
	public:
		bool insert(const K& key)
		{
			return tb_.Insert(key);
		}
		bool erase(const K& key)
		{
			return tb_.Erase(key);
		}
	private:

		hash_bucket::HashTable<K, K, KeyOfSet> tb_;
	};
}