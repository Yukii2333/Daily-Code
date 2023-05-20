#include <iostream>

using namespace std;

int main()
{
	int* p1 = new int;
	int* p2 = new int[10];

	delete p1;
	delete[] p2;
	return 0;
}

//int main() 
//{
//    int* p1;
//    try
//    {
//        do
//        {
//            p1 = new int[1024 * 1024];
//        } while (p1);
//    }
//    catch (const exception& e)
//    {
//        cout << e.what() << endl;
//    }
//
//    return 0;
//}
