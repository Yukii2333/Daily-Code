#pragma once

#include<iostream>
#include<assert.h>

namespace L
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
        {
            _pPre = _pNext = this;
            _val = val;
        }
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    class ListIterator
    {
        typedef ListNode<T> Node;
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
    public:
        PNode _pNode;

        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        {}
        ListIterator(const Self& l)
            :_pNode(l._pNode)
        {}
        T& operator*()
        {
            return _pNode->_val;
        }

        T* operator->()
        {
            return &_pNode->_val;
        }
        //前置++
        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }
        //后置++
        Self operator++(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pNext;
            return tmp;
        }
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }
        Self& operator--(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pPre;
            return tmp;
        }
        bool operator!=(const Self& l)
        {
            return _pNode != l._pNode;
        }
        bool operator==(const Self& l)
        {
            return _pNode == l._pNode;
        }
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
        {
            _pHead = new Node;
            _size = 0;
        }
        list(int n, const T& value = T())
        {
            _pHead = new Node;
            _size = n;
            PNode cur = _pHead;
            while (n--)
            {
                PNode newnode = new Node(value);
                cur->_pNext = newnode;
                newnode->_pPre = cur;
                newnode->_pNext = _pHead;
                _pHead->_pPre = newnode;
                cur = newnode;
            }
        }
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            _pHead = new Node;
            _size = 0;
            PNode cur = first;
            PNode _cur = _pHead;
            while (cur != last)
            {
                PNode newnode = new Node(cur->_val);
                cur++;
                _cur->_pNext = newnode;
                newnode->_pPre = _cur;
                newnode->_pNext = _pHead;
                _pHead->_pPre = newnode;
                _cur = newnode;
                _size++;
            }
        }
        list(const list<T>& l)
        {
            _pHead = new Node;
            list tmp;
            tmp = l;
            swap(*this, tmp);
        }
        list<T>& operator=(const list<T> l)
        {
            clear();
            PNode _cur = _pHead;
            iterator it = l.begin();
            while (it != l.end())
            {
                PNode newnode = new Node(*it);
                it++;
                _cur->_pNext = newnode;
                newnode->_pPre = _cur;
                newnode->_pNext = _pHead;
                _pHead->_pPre = newnode;
                _cur = newnode;
                _size++;
            }

        }
        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
        }


        /////////////////////////////////////////////////////////////
        //List Iterator
        iterator begin()
        {
            return iterator(_pHead->_pNext);
        }
        iterator end()
        {
            return iterator(_pHead);
        }
        const_iterator begin() const
        {
            return iterator(_pHead->_pNext);
        }
        const_iterator end() const
        {
            return iterator(_pHead);
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            return _size;
        }
        bool empty()const
        {
            return _size == 0;
        }


        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return _pHead->_pNext->_val;
        }
        T& front()const
        {
            return _pHead->_pNext->_val;
        }
        T& back()
        {
            return _pHead->_pPre->_val;
        }
        T& back()const
        {
            return _pHead->_pPre->_val;
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val)
        {
            insert(begin(), val);
        }
        void pop_back()
        {
            erase(--end());
        }
        void push_front(const T& val)
        {
            insert(begin(), val);
        }
        void pop_front() {
            erase(begin());
        }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            PNode cur = pos._pNode;
            PNode newnode = new Node(val);
            newnode->_pNext = cur;
            newnode->_pPre = cur->_pPre;
            cur->_pPre->_pNext = newnode;
            cur->_pPre = newnode;
            return newnode;
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            assert(pos != end());
            PNode cur = pos._pNode;
            PNode pre = cur->_pPre;
            PNode next = cur->_pNext;
            pre->_pNext = next;
            next->_pPre = pre;
            delete cur;
            --_size;
            return next;
        }
        void clear()
        {
            iterator it = begin();
            while (it != end())
            {
                it = erase(it);
            }
            _size = 0;
        }
        void swap(list<T>& l)
        {
            std::swap(_pHead, l._pHead);
            std::swap(_size, l._size);
        }

    private:
        PNode _pHead;
        size_t _size;
    };
};