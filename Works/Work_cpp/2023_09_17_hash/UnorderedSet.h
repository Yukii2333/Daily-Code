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
		typedef typename hash_bucket::HashTable<K, K, KeyOfSet>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, K, KeyOfSet>::const_iterator const_iterator;

		iterator begin() const
		{
			return ht_.begin();
		}
		iterator end() const
		{
			return ht_.end();
		}
	public:
		std::pair<const_iterator, bool> insert(const K & key)
		{
			std::pair<typename hash_bucket::HashTable<K, K, KeyOfSet>::iterator, bool> rt = ht_.Insert(key);
			return std::make_pair(rt.first,rt.second);
		}

	private:

		hash_bucket::HashTable<K, K, KeyOfSet> ht_;
	};
}