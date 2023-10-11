#pragma

#include<iostream>

namespace MySTL
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* str)
			:ptr_(str)
		{}
		auto_ptr(auto_ptr<T>& a)
			:ptr_(a.ptr_)
		{
			a.ptr_ = nullptr;
		}
		~auto_ptr()
		{
			if (ptr_) delete ptr_;
		}
		auto_ptr<T> operator=(auto_ptr<T>& a)
		{
			if (ptr_) delete ptr_;
			ptr_ = a.ptr_;
			a.ptr_ = nullptr;
			return *this;
		}
		T& operator*()
		{
			return *ptr_;
		}
		T* operator->()
		{
			return ptr_;
		}

	private:
		T* ptr_;
	};

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* str)
			:ptr_(str)
		{}
		unique_ptr(unique_ptr<T>& u) = delete;
		~unique_ptr()
		{
			if (ptr_) delete ptr_;
		}
		unique_ptr<T> operator=(unique_ptr<T>& u) = delete;

		T& operator*()
		{
			return *ptr_;
		}
		T* operator->()
		{
			return ptr_;
		}

	private:
		T* ptr_;
	};

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* str)
			:ptr_(str)
			,pcount_(new int(1))
		{}
		shared_ptr(shared_ptr<T>& s)
		{
			ptr_ = s.ptr_;
			pcount_ = s.pcount_;
			++ *pcount_;
		}
		~shared_ptr()
		{
			if (-- *pcount_ == 0)
			{
				delete ptr_;
				delete pcount_;
			}
		}
		T* get()
		{
			return ptr_;
		}
		shared_ptr<T> operator=(shared_ptr<T>& s)
		{
			if (ptr_ == s.ptr_) return *this;
			if (ptr_ && -- *pcount_ == 0)
			{
				delete ptr_;
				delete pcount_;
			}
			ptr_ = s.ptr_;
			pcount_ = s.pcount_;
			++ *pcount_;
			return *this;
		}
		T& operator*()
		{
			return *ptr_;
		}
		T* operator->()
		{
			return ptr_;
		}

	private:
		T* ptr_ = nullptr;
		int* pcount_ = nullptr;
	};

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr(T* str)
			:ptr_(str)
		{}
		weak_ptr(shared_ptr<T>& s)
		{
			ptr_ = s.get();
		}
		~weak_ptr(){}
		weak_ptr<T> operator=(shared_ptr<T>& s)
		{
			ptr_ = s.get();
			return *this;
		}
		T& operator*()
		{
			return *ptr_;
		}
		T* operator->()
		{
			return ptr_;
		}

	private:
		T* ptr_ = nullptr;
	};
}