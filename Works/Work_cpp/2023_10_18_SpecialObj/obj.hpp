#pragma
#include<iostream>
using namespace std;

class HeapOnly
{
public:
	static HeapOnly* Create()
	{
		if (hp_ == nullptr)
		{
			hp_ = new HeapOnly();
		}
		return hp_;
	}
	~HeapOnly() {};
private:
	HeapOnly() {};
	HeapOnly(const HeapOnly& hp) {};
	HeapOnly& operator=(const HeapOnly& hp) {};

	static HeapOnly* hp_;
};

HeapOnly* HeapOnly::hp_ = nullptr;

class StackOnly
{
public:
	static StackOnly Create()
	{
		StackOnly st;
		return st;
	}
private:
	StackOnly() {};
	void* operator new(size_t size) = delete;
};

class BanCopy
{
public:
	BanCopy() {};

private:
	BanCopy& operator=(const BanCopy& bc) = delete;
	BanCopy(const BanCopy& bc) = delete;
};

class BanInherit final
{
public:
	BanInherit() {};
private:
};

namespace hungry
{
	class singleton
	{
	public:
		static singleton& Create()
		{
			return sl_;
		}
	private:
		singleton() {};
		singleton& operator=(const singleton& sl) = delete;
		singleton(const singleton& sl) = delete;

	private:
		static singleton sl_;
	};
	singleton singleton::sl_;
}

namespace lazy
{
	class singleton
	{
	public:
		static singleton* Create()
		{
			if (sl_ == nullptr)
			{
				sl_ = new singleton;
			}
			return sl_;
		}
		static void Del_singleton()
		{
			if (sl_) delete sl_;
			sl_ = nullptr;
		}
	private:
		singleton() {};
		~singleton() {};
		singleton& operator=(const singleton& sl) = delete;
		singleton(const singleton& sl) = delete;
		

	private:
		static singleton* sl_;
	};
	singleton* singleton::sl_=nullptr;
}