#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"bitset.h"

//�������ֲ�ͬ���ַ���ӳ��ֵ�ķ���
struct BKDRHash
{
	size_t operator()(const std::string& s)
	{
		// BKDR
		size_t value = 0;
		for (auto ch : s)
		{
			value *= 31;
			value += ch;
		}
		return value;
	}
};
struct APHash
{
	size_t operator()(const std::string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
			}
		}
		return hash;
	}
};
struct DJBHash
{
	size_t operator()(const std::string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

namespace MyStd
{
	template<size_t N,
			class K = std::string, 
			class HashFunc1 = BKDRHash,
			class HashFunc2 = APHash,
			class HashFunc3 = DJBHash>
	class BloomFilter
	{
	public:
		//������ͬ�Ķ�Ӧֵ�����ͳ�ͻ
		//��ͻֻ�ܽ��ͣ����ܱ���
		void set(const K& key)
		{
			size_t len = N;
			size_t index1 = HashFunc1()(key) % len;
			size_t index2 = HashFunc2()(key) % len;
			size_t index3 = HashFunc3()(key) % len;
			bitset_.set(index1);
			bitset_.set(index2);
			bitset_.set(index3);
		}
		//���ڳ�ͻ��ԭ�򣬼�����������Ӧֵ�����ڣ�Ҳֻ��˵��Ŀ��Ԫ�ؿ��ܴ���
		//�����������㶼���ڣ���ôĿ��Ԫ��һ��������
		bool test(const K& key)
		{
			size_t len = N;
			size_t index1 = HashFunc1()(key) % len;
			if (bitset_.test(index1) == false)
			{
				return false;
			}
			size_t index2 = HashFunc2()(key) % len;
			if (bitset_.test(index2) == false)
			{
				return false;
			}
			size_t index3 = HashFunc3()(key) % len;
			if (bitset_.test(index3) == false)
			{
				return false;
			}

			return true;
		}
	private:
		bitset<N> bitset_;
	};
}