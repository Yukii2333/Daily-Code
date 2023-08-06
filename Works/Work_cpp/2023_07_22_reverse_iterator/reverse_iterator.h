#pragma once

#include<iostream>

namespace RE_IT
{
	template<class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ref, Ptr> Self;
		Iterator _it;

		Reverse_iterator(Iterator it):_it(it){}

		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}
		Ptr operator->()
		{
			return &(operator*());
		}
		Self& operator++()
		{
			--_it;
			return *this;
		}
		Self& operator--()
		{
			++_it;
			return *this;
		}
		bool operator!=(const Self& s) const
		{
			return _it != s._it;
		}
	};
}