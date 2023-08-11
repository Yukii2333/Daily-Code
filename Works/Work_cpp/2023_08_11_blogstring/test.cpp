#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

void test1()
{
    string s("Hello World!");
    cout << s.size() << endl;           //���s����Ч�ַ�������12����lenth()Ч����ͬ��һ�㳣��size()
    cout << s.capacity() << endl;       //���s�����������ݱ�������ͬ���Ҳ��������ͬ��
    cout << s.c_str() << endl;
    string s1(s);
    s.clear();                      //���s
    if (s1.empty())                  //empty()��������Ϊbool
    {
        cout << "s1 empty!" << endl;
    }
    if (s.empty())
    {
        cout << "s empty!" << endl;
    }
    s.resize(3, 'a');                  //��s���ַ�����Ϊ3��������a���ǣ�string���л���һ�����غ���������ֻ��size_t n������Ŀռ���0���
    //resize()�����ֵ
    s1.resize(5);                  //��s1���ַ�����Ϊ5�������ֱ����ȥ
    cout << s.size() << endl;
    cout << s1.size() << endl;
}

void test2()
{
    string s;
    s.push_back('a');
    s += "bcd";
    cout << s.c_str() << endl;
    if (s.find('e') == (size_t)-1)
    {
        cout << "don't find it!" << endl;
    }
}

int main()
{
    test2();
	return 0;
}