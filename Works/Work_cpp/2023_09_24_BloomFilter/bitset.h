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
			//������Ҫ��λ
			a_.resize(N / 32 + 1, 0);
		}
		//��x��Ӧ��λ�޸�Ϊ1
		void set(size_t x)
		{
			//��i��λ�õĵ�j��λ
			int i = x / 32;
			int j = x % 32;
			a_[i] |= (1 << j);
		}
		//��x��Ӧ��λ�޸�Ϊ0
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