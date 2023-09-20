#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<time.h>
#include<unordered_set>
#include<unordered_map>
//#include"HashTable.h"
//#include"UnorderedSet.h"
#include"UnorderedMap.h"

using namespace std;

int main()
{
	MySTL::unordered_map<string, string> m2;
	m2.insert(make_pair("sort", "排序"));
	m2.insert(make_pair("left", "左"));
	m2.insert(make_pair("right", "右"));
	m2.insert(make_pair("quit", "结束"));
	m2["ygyg"] = "一个一个";
	for (auto& e : m2)
	{
		cout << e.first << ":" << e.second << endl;
	}
	return 0;
}

//int main()
//{
//	HashTable<int ,int> table;
//	srand(time(0));
//	table.Insert(4);
//	table.Insert(44);
//	table.Insert(14);
//	table.Insert(34);
//	table.Insert(3);
//	table.Insert(6);
//	//table.Insert(7);
//	//table.Insert(5);
//	//table.Insert(15);
//	//for (size_t i = 0; i < 10; ++i)
//	//{
//	//	table.Insert(rand());
//	//}
//	table.Print();
//	table.Erase(4);
//	table.Erase(34);
//	table.Erase(44);
//	table.Erase(14);
//	return 0;
//}