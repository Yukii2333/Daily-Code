#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//#include<set>
//void TestSet()
//{
//    int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//    set<int> s(array, array + sizeof(array) / sizeof(array));
//    cout << s.size() << endl;
//    for (auto& e : s)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//    for (auto it = s.rbegin(); it != s.rend(); ++it)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
//    cout << s.count(3) << endl;
//}

//#include<map>
//#include<string>
//#include<vector>
//void test()
//{
//    vector<string> words{ "key","value","value","code","hello","value","world" };
//    map<string, int> m;
//    m.insert(make_pair("key", 1));
//    m.insert(make_pair("code", 1));
//    m.insert(make_pair("value", 1));
//    for (auto& e : m)
//    {
//        cout << e.first << " " << e.second << endl;
//    }
//    cout << endl;
//    for (auto& e : words)
//    {
//        m[e]++;
//    }
//    for (auto& e : m)
//    {
//        cout << e.first << " " << e.second << endl;
//    }
//    cout << endl;
//    for (auto it = m.rbegin(); it != m.rend(); ++it)
//    {
//        cout << it->first << " " << it->second << endl;
//    }
//    cout << m.count("value") << endl;
//}

#include<set>
void test()
{
    int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
    multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
    for (auto& e : s)
    {
        cout << e << " ";
    }
    cout << endl;
    s.insert(array, array + sizeof(array) / sizeof(array[0]));
    for (auto& e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}



int main()
{
    test();
    return 0;
}