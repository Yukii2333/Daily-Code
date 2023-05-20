#include <iostream>

using namespace std;

int main() {
    int* p1;
    do
    {
        p1 = new int[1024*1024];
    }while(p1);
    return 0;
}
