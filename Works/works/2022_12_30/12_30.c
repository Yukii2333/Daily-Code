#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main() {
    int m = 0;
    scanf("%d", &m);
    int count = m;
    int i = 1;
    int tmp = 0;
    int tmp2 = 0;
    int result = pow(m, 3);
    int r = 0;
    while (r != result)
    {
        tmp = i;
        tmp2 = i;
        while (count != 1)
        {
            tmp2 += 2;
            tmp = tmp2 + tmp;
            count--;
        }
        count = m;
        if (tmp == result)
        {
            r = tmp;
        }
        else
        {
            i += 2;
        }
    }
    while (count)
    {
        if (count < m)
        {
            printf("+");
        }
        printf("%d", i);
        i += 2;
        count--;
    }
    return 0;
}