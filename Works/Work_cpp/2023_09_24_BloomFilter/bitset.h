#pragma once

#include <iostream>
#include <vector>

namespace MyStd
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			//计算需要的位
			a_.resize(N / 32 + 1, 0);
		}
		//将x对应的位修改为1
		void set(size_t x)
		{
			//第i个位置的第j个位
			int i = x / 32;
			int j = x % 32;
			a_[i] |= (1 << j);
		}
		//将x对应的位修改为0
		void reset(size_t x)
		{
			int i = x / 32;
			int j = x % 32;
			a_[i] &= (~(1 << j));
		}
		bool test(size_t x)
		{
			int i = x / 32;
			int j = x % 32;
			return a_[i] & (1 << j);
		}
	private:
		std::vector<int> a_;
	};
}