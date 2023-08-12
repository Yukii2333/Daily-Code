#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;

//void test()
//{
//    string s("Hello world!");
//    //用方括号遍历字符串，运算符重载
//    for (int i = 0; i < s.size(); ++i)
//    {
//        cout << s[i];
//    }
//    cout << endl;
//    //迭代器遍历
//    string::iterator it = s.begin();
//    while (it != s.end())
//    {
//        cout << *it;
//        ++it;
//    }
//    cout << endl;
//    //反向迭代器遍历
//    string::reverse_iterator r_it = s.rbegin();
//    while (r_it != s.rend())
//    {
//        cout << *r_it;
//        ++r_it;
//    }
//    cout << endl;
//    //范围for遍历
//    for (auto a_it : s)
//    {
//        cout << a_it;
//    }
//    cout << endl;
//}

void test()
{
	string s1("Hello ");
	string s2("World!");
	string s3 = s1 + s2;
	cout << s3 << endl;
	

	getline(cin, s3);
	cout << s3 << endl;

	cin >> s3;
	cout << s3 << endl;

	if (s1 > s2)
	{
		cout << s1 << endl;
	}
	else
	{
		cout << s2 << endl;
	}
}

int main()
{
    //test();
	string s("1111");
	return 0;
}