#pragma once

#include<iostream>
#include"RBTRee.h"


namespace MyStd
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const std::pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
		typedef typename RBTree<K, std::pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, std::pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;
	public:
		iterator begin()
		{
			return t_.begin();
		}
		iterator end()
		{
			return t_.end();
		}
		const_iterator begin() const
		{
			return t_.begin();
		}
		const_iterator end() const
		{
			return t_.end();
		}
		bool Insert(K& key, V& val)
		{
			return t_.Insert(std::make_pair(key, val));
		}
	private:
		

		RBTree<K, std::pair<const K, V>, MapKeyOfT> t_;
	};
}