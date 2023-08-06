#pragma once

#include<vector>
#include<functional>

template<class T>
class Less
{
public:
    bool operator()(const T& x, const T& y)
    {
        return x < y;
    }
};

template<class T>
class Greater
{
public:
    bool operator()(const T& x, const T& y)
    {
        return x > y;
    }
};

namespace PQ
{
    template <class T, class Container = std::vector<T>, class Compare = less<T>>
    class priority_queue
    {
    private:
        void AdjustDown(int parent)
        {
            int child = parent * 2 - 1;
            while (child < _c.size())
            {
                if (child + 1 < _c.size() && _comp(_c[child+1], _c[child]))
                {
                    ++child;
                }
                if (_comp(_c[child], _c[parent]))
                {
                    std::swap(_c[child], _c[parent]);
                    parent = child;
                    child = parent * 2 - 1;
                }
                else
                {
                    break;
                }
            }
        }
        void AdjustUp(int child)
        {
            int parent = (child - 1) / 2;
            while (parent > 0)
            {
                if (child + 1 < _c.szie() && _comp(_c[child + 1], _c[child]))
                {
                    ++child;
                }
                if (_comp(_c[child], _c[parent]))
                {
                    std::swap(_c[child], _c[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }
    public:
        priority_queue(){}
        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                _c.push_back(*first);
                first++;
            }
            for (size_t i = (_c.size() - 1) / 2; i > 0; --i)
            {
                AdjustDown(i);
            }
        }
        bool empty() const
        {
            return _c.empty();
        }
        size_t size() const
        {
            return _c.size();
        }
        T top() const
        {
            return _c[0];
        }
        void push(const T& x)
        {
            _c.push_back(x);
            AdjustUp(_c.size() - 1);

        }
        void pop()
        {
            std::swap(_c[0],_c[_c.size() - 1]);
            _c.pop_back();
            AdjustDown(0);
        }
    private:
        Container _c;
        Compare _comp;
    };
};