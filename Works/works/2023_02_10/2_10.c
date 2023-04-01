#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAX(x,y) ((x)>(y)?(x):(y))

int Max(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    int a = 1;
    int b = 2;
    int c = MAX(a++, b++);
    a = 1;
    b = 2;
    int d = Max(a++, b++);
    printf("%d %d\n", c, d);
    return 0;
}