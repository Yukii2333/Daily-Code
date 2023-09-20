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
		typedef typename hash_bucket::HashTable<K, std::pair<const K, V>, KeyOfMap>::iterator iterator;
		typedef typename hash_bucket::HashTable<K, std::pair<const K, V>, KeyOfMap>::const_iterator const_iterator;

		iterator begin()
		{
			return ht_.begin();
		}
		iterator end()
		{
			return ht_.end();
		}

		const_iterator begin() const
		{
			return ht_.begin();
		}
		const_iterator end() const
		{
			return ht_.end();
		}
	public:
		std::pair<iterator, bool> insert(const std::pair<K, V> kv)
		{
			return ht_.Insert(kv);
		}
		V& operator[](const K& key)
		{
			std::pair<iterator, bool> rt = insert(std::pair<K, V>(key, V()));
			return rt.first->second;
		}
	private:
		hash_bucket::HashTable<K, std::pair<const K, V>, KeyOfMap> ht_;
	};
}