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
		//���캯��
		//���ַ����ַ����Լ�string��
		string(const char* str = "");
		string(const string& s);
		//��ֵ
		string& operator=(const string& s);

		//������
		iterator begin();
		const iterator begin() const;
		iterator end();
		const iterator end() const;

		//�޸�
		void push_back(char c);
		string& operator+=(char c);
		void append(const char* str);
		string& operator+=(const char* str);
		void clear();
		void swap(string& s);
		const char* c_str()const;

		//ȡ��
		char& operator[](size_t index);
		const char& operator[](size_t index)const;

		//�Ƚ�
		const bool operator<(const string& s) const;
		const bool operator<=(const string& s) const;
		const bool operator>(const string& s) const;
		const bool operator>=(const string& s) const;
		const bool operator==(const string& s) const;
		const bool operator!=(const string& s) const;

		//����
		size_t find(char c, size_t pos = 0) const;
		size_t find(const char* str, size_t pos = 0) const;

		//����
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);

		//ɾ��
		string& erase(size_t pos, size_t len = -1);

		//����
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