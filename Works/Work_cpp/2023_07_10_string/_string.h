#pragma once

#include<iostream>
#include<assert.h>

namespace Str
{
	class string
	{

	public:
		typedef char* iterator;
	public:
		//构造函数
		//单字符、字符串以及string类
		string(const char* str = "");
		string(const string& s);
		//赋值
		string& operator=(const string& s);

		//迭代器
		iterator begin();
		const iterator begin() const;
		iterator end();
		const iterator end() const;

		//修改
		void push_back(char c);
		string& operator+=(char c);
		void append(const char* str);
		string& operator+=(const char* str);
		void clear();
		void swap(string& s);
		const char* c_str()const;

		//取出
		char& operator[](size_t index);
		const char& operator[](size_t index)const;

		//比较
		const bool operator<(const string& s) const;
		const bool operator<=(const string& s) const;
		const bool operator>(const string& s) const;
		const bool operator>=(const string& s) const;
		const bool operator==(const string& s) const;
		const bool operator!=(const string& s) const;

		//查找
		size_t find(char c, size_t pos = 0) const;
		size_t find(const char* str, size_t pos = 0) const;

		//插入
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);

		//删除
		string& erase(size_t pos, size_t len = -1);

		//析构
		~string()
		{
			delete[] _str;
			_capacity = 0;
			_size = 0;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}