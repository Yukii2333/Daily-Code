#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

void test1()
{
    string s("Hello World!");
    cout << s.size() << endl;           //输出s的有效字符个数（12），lenth()效果相同，一般常用size()
    cout << s.capacity() << endl;       //输出s的容量（根据编译器不同结果也会有所不同）
    cout << s.c_str() << endl;
    string s1(s);
    s.clear();                      //清空s
    if (s1.empty())                  //empty()返回类型为bool
    {
        cout << "s1 empty!" << endl;
    }
    if (s.empty())
    {
        cout << "s empty!" << endl;
    }
    s.resize(3, 'a');                  //将s的字符数改为3个，并用a覆盖，string类中还有一个重载函数，参数只有size_t n，多出的空间用0填充
    //resize()传入的值
    s1.resize(5);                  //将s1的字符数改为5，多余的直接舍去
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