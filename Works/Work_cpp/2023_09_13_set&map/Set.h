#pragma once

#include<iostream>
#include"RBTRee.h"

namespace MyStd
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		typedef typename RBTree<K, const K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, const K, SetKeyOfT>::const_iterator const_iterator;

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
		bool Insert(const K& key)
		{
			return t_.Insert(key);
		}
	private:
		RBTree<K, const K, SetKeyOfT> t_;
	};
}