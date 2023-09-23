#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<time.h>
#include<unordered_set>
#include<unordered_map>
#include"HashTable.h"
#include"UnorderedSet.h"
#include"UnorderedMap.h"

using namespace std;

int main()
{
	MySTL::unordered_map<string, string> m2;
	m2.insert(make_pair("sort", "ÅÅĞò"));
	m2.insert(make_pair("left", "×ó"));
	m2.insert(make_pair("right", "ÓÒ"));
	m2.insert(make_pair("quit", "½áÊø"));
	m2["ygyg"] = "Ò»¸öÒ»¸ö";
	for (auto& e : m2)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
	MySTL::unordered_set<string> s;
	s.insert("sort");
	s.insert("quit");
	s.insert("hash");
	s.insert("exist");
	s.insert("delete");
	for (auto& e : s)
	{
		cout << e << endl;
	}
	return 0;
}

//int main()
//{
//	hash_table::HashTable<string, string> t;
//	t.Insert(make_pair("sort", "ÅÅĞò"));
//	t.Insert(make_pair("quit", "ÍË³ö"));
//	t.Insert(make_pair("hash", "¹şÏ£"));
//	t.Insert(make_pair("test", "²âÊÔ"));
//	t.Insert(make_pair("hash_", "¹şÏ£"));
//	t.Print();
//	return 0;
//}

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