#include <iostream>

using namespace std;

int main() {
    string str1("ygygygyg");
    string str2;
    str2 = str1;
    str1 += str2;
    string *str3;
    str3 = new string;
    *str3 = str1;
    cout<<*str3<<endl;
    cout<<str2<<endl;
    cout<<str1<<endl;
    return 0;
}
