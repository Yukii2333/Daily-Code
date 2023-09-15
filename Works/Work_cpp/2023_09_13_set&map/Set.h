#pragma once

#include"RBTree.h"

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
		//不论是iterator还是const_iterator，都是const类型
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

	public:
		iterator begin() const
		{
			return t_.begin();
		}
		iterator end() const
		{
			return t_.end();
		}
		std::pair<iterator, bool> Insert(const K& key)
		{
			std::pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = t_.Insert(key);
			return std::pair<iterator, bool>(ret.first, ret.second);
		}
	private:
		RBTree<K, K, SetKeyOfT> t_;
	};
}