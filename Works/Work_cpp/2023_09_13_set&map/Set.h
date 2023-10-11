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
			//Insert的返回类型是普通类型的iterator，而set中的iterator是const类型，不能直接接收
			//先用一个普通的类型接受后
			//再用普通类型去构建const类型（此处需要迭代器添加一个构造函数）
			std::pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = t_.Insert(key);
			return std::pair<iterator, bool>(ret.first, ret.second);
		}
	private:
		RBTree<K, K, SetKeyOfT> t_;
	};
}