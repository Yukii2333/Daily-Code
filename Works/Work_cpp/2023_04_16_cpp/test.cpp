#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

int main()
{
	int a = 10;
	float b = 3.1415;
	std::cin >> a;
	std::cin >> b;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	return 0;
}

//namespace yuki
//{
//    int rand = 10;
//
//    int Add(int a, int b)
//    {
//        return a + b;
//    }
//
//    struct Node
//    {
//        struct Node* next;
//        int data;
//    };
//
//    namespace yukii
//    {
//        int rand = 9;
//    }
//}
//
//int rand = 8;
//
//int main()
//{
//    int rand = 7;
//    printf("%d\n", yuki::yukii::rand);
//	return 0;
//}