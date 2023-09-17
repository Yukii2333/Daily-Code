#pragma once

#include<iostream>
#include"HashTable.h"

namespace MySTL
{
	template<class K, class V>
	class unordered_map
	{
		struct KeyOfMap
		{
			const K& operator()(const std::pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, std::pair<K, V>, KeyOfMap>::iterator iterator;

		iterator begin()
		{
			return tb_.begin();
		}
		iterator end()
		{
			return tb_.end();
		}
	public:
		bool insert(const std::pair<K, V> kv)
		{
			return tb_.Insert(kv);
		}
		bool find(const std::pair<K, V> kv)
		{
			return tb_.Find(kv);
		}
	private:
		hash_bucket::HashTable<K, std::pair<K, V>, KeyOfMap> tb_;
	};
}