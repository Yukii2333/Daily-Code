#define _CRT_SECURE_NO_WARNINGS 1

#include"_string.h"
//构造
Str::string::string(const char* str)
{
	_size = strlen(str);
	_capacity = _size == 0 ? 1 : _size * 2;
	_str = new char[_capacity];
	memcpy(_str, str, _size + 1);
}
Str::string::string(const Str::string& s)
{
	_size = s._size;
	_capacity = s._capacity;
	_str = new char[_capacity];
	memcpy(_str, s._str, _size + 1);
}

//迭代器
Str::string::iterator Str::string::begin()
{
	return _str;
}
Str::string::iterator Str::string::end()
{
	return (_str + _size);
}
const Str::string::iterator Str::string::begin() const
{
	return _str;
}
const Str::string::iterator Str::string::end() const
{
	return (_str + _size);
}

//修改
void Str::string::push_back(char c)
{
	if (_size + 1 == _capacity)
	{
		_capacity *= 2;
		char* tmp = new char[_capacity];
		memcpy(tmp, _str, _size + 1);
		delete[] _str;
		_str = tmp;
	}
	_str[_size++] = c;
	_str[_size] = '\0';
}


Str::string& Str::string::operator=(const Str::string& s)
{
	if (_capacity > s._size)
	{
		_size = s._size;
		memcpy(_str, s._str, _size + 1);
		return *this;
	}
	_capacity = s._capacity;
	_size = s._size;
	delete[] _str;
	_str = new char[_capacity];
	memcpy(_str, s._str, _size + 1);
	return *this;
}

Str::string& Str::string::operator+=(char c)
{
	this->push_back(c);
	return *this;
}

void  Str::string::append(const char* str)
{
	size_t len = strlen(str);
	if (_size + len + 1 > _capacity)
	{
		_capacity = _size + len + 1;
		char* tmp = new char[_capacity];
		memcpy(tmp, _str, _size + 1);
		delete[] _str;
		_str = tmp;
	}
	memcpy(_str + _size, str, len + 1);
	_size += len;
}

Str::string& Str::string::operator+=(const char* str)
{
	this->append(str);
	return *this;
}

void Str::string::clear()
{
	_str[0] = '\0';
	_size = 0;
}

void Str::string::swap(Str::string& s)
{
	Str::string tmp = s;
	s = *this;
	*this = tmp;
}

const char* Str::string::c_str()const
{
	return _str;
}

//取出
char& Str::string::operator[](size_t index)
{
	assert(index <= _size);
	return _str[index];
}
const char& Str::string::operator[](size_t index)const
{
	assert(index <= _size);
	return _str[index];
}

//比较
const bool Str::string::operator<(const Str::string& s) const
{
	return _size < s._size;
}
const bool Str::string::operator<=(const Str::string& s) const
{
	return *this < s || *this == s;
}
const bool Str::string::operator>(const Str::string& s) const
{
	return _size > s._size;
}
const bool Str::string::operator>=(const Str::string& s) const
{
	return *this > s || *this == s;
}
const bool Str::string::operator==(const Str::string& s) const
{
	if (*this > s || *this < s)
		return false;
	return strcmp(_str, s._str) == 0;
}
const bool Str::string::operator!=(const Str::string& s) const
{
	return !(*this == s);
}

//查找
size_t  Str::string::find(char c, size_t pos) const
{
	assert(pos < _size);
	Str::string::iterator it = this->begin();
	while (it != this->end())
	{
		if (*it++ == c)
			return pos;

		pos++;
	}
	return -1;
}
size_t Str::string::find(const char* str, size_t pos) const
{
	assert(pos < _size);
	size_t len = strlen(str);
	Str::string::iterator it = this->begin();
	while (it != (this->end()-len+1))
	{
		int flag = 0;
		for (int i = 0; i < len; ++i)
		{
			if (*(it + i) != *(str + i))
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
			return pos;

		it++;
		pos++;
	}
	return -1;
}

//插入
Str::string& Str::string::insert(size_t pos, char c)
{
	assert(pos < _size);
	if (_size + 2 > _capacity)
	{
		_capacity = _size + 1;
		char* tmp = new char[_capacity];
		memcpy(tmp, _str, _size + 1);
		delete[] _str;
		_str = tmp;
	}
	size_t n = _size - pos+1;
	Str::string::iterator it = this->end();
	while (n--)
	{
		*(it+1) = *it;
		it--;
	}
	_str[pos] = c;
	_size += 1;
	return *this;
}
Str::string& Str::string::insert(size_t pos, const char* str)
{
	assert(pos < _size);
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		_capacity = _size + len + 1;
		char* tmp = new char[_capacity];
		memcpy(tmp, _str, _size + 1);
		delete[] _str;
		_str = tmp;
	}
	size_t n = _size - pos+1;
	Str::string::iterator it = this->end();
	size_t sit = len-1;
	while (n--)
	{
		*(it+len) = *it;
		it--;
	}
	for (int i = 0; i < len; ++i)
	{
		_str[pos + i] = *(str + i);
	}
	_size += len;
	return *this;
}

//删除
Str::string& Str::string::erase(size_t pos, size_t len)
{
	assert(pos < _size);
	if (pos + len > _size)
	{
		_str[pos] = '\0';
		_size = pos;
		return *this;
	}
	int n = _size - pos - len+1;
	while (n--)
	{
		_str[pos] = _str[pos + len];
		pos++;
	}
	_size -= len;
	return *this;
}