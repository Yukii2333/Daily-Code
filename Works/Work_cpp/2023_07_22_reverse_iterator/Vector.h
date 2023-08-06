#pragma

#include<iostream>
#include<assert.h>
#include"reverse_iterator.h"



namespace V
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* iterator_const;
		typedef RE_IT::Reverse_iterator<iterator, T&, T*> reverse_iterator;
	public:
		//迭代器
		iterator begin()
		{
			return _start;
		}
		iterator end() 
		{
			return _finish;
		}
		iterator_const begin() const
		{
			return _start;
		}
		iterator_const end() const
		{
			return _start;
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		//构造
		vector() 
		{}
		vector(size_t n, const T& val = T())
		{
			resize(n, val);
		}
		vector(int n, const T& val = T())
		{
			resize(n, val);
		}
		vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}

			_finish = _start + v.size();
			_endOfStorage = _start + v.capacity();
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endOfStorage = _start + n;
			}
		}

		void resize(size_t n, const T& x = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = x;
					++_finish;
				}
			}
		}

		//修改
		void push_back(const T& x)
		{
			if (_finish == _endOfStorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back(const T& x)
		{
			if (_finish == _endOfStorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			for (size_t i = size(); i > 0; --i)
			{
				_start[i] = _start[i - 1];
			}
			_start[0] = x;
			++_finish;
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			size_t len = pos - _start;
			if (_finish == _endOfStorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + len;
			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);
			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish;
			return pos;
		}


		//运算符重载
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		//交换
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}


		//数据量以及空间量
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
			}
		}
	private:
		iterator _start = nullptr; 
		iterator _finish = nullptr; 
		iterator _endOfStorage = nullptr; 
	};


}
