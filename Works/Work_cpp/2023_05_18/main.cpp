#include <iostream>

using namespace std;

class A
{
public:
    A(int a = 0)
        :a_(a)
    {
        cout<<"A()"<<this<<endl;
    }
    ~A()
    {
        cout<<"~A()"<<endl;
    }
private:
    int a_;
};


int main()
{
    A* a1 = new A;
    A* a2 = new A(10);
    A* a3 = new A[3];

    delete a1;
    delete a2;
    delete[] a3;
    return 0;
}

/*int main()
{
    int* ptr1 = new int;
    int* ptr2 = new int(10);
    int* ptr3 = new int[3];


    delete ptr1;
    delete ptr2;
    delete[] ptr3;
    return 0;
}*/

/*int main()
{
    int* p1 = (int*)malloc(sizeof(int));
    free(p1);

    int* p2 = (int*)calloc(4,sizeof(int));
    int* p3 = (int*)realloc(p2,sizeof(int)*10);

    free(p3);
    return 0;
}*/




/*

template <typename T>
T Add(T a,T b)
{
    return a+b;
}

int main()
{
    cout<<Add(1,2)<<endl;
    cout<<Add(1.1,1.2)<<endl;
    cout <<Add<float>(1.1, 2)<< endl;
    return 0;
}*/

/*int main() {
    string* arr = new string[5];
    delete arr;
    return 0;
}*/
