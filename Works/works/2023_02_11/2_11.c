#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

void find_del(char* str1, const char* str2)
{
    assert(str1 != NULL && str2 != NULL);
    int len = strlen(str1);
    int i = 0;
    while (*(str2 + i) != '\0')
    {
        int j = 0;
        while (*(str1 + j) != '\0')
        {
            if (*(str1 + j) == *(str2 + i))
            {
                int k = j;
                for (; k < len - 1; k++)
                {
                    *(str1 + k) = *(str1 + k + 1);
                    if (k == len - 2)
                    {
                        *(str1 + k + 1) = '\0';
                        len--;
                        j--;
                    }
                }
            }
            j++;
        }
        i++;
    }
}

int main()
{
    char arr1[100] = { 0 };
    char arr2[100] = { 0 };
    gets(arr1);
    gets(arr2);
    find_del(arr1, arr2);
    printf("%s\n", arr1);
    return 0;
}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char num[14] = { 0 };
//    char tmp[14] = { 0 };
//    scanf("%s", num);
//    int len = strlen(num);
//    int tmp1 = len;
//    int j = 0;
//    int i = 0;
//    for (j = 0; j < len; j++)
//    {
//        if (j != 0 && j % 3 == 0 && j != len)
//        {
//            tmp[i] = ',';
//            i++;
//        }
//        tmp[i] = num[tmp1 - 1];
//        tmp1--;
//        i++;
//    }
//    j = 0;
//    for (; i > 0; i--)
//    {
//        num[j] = tmp[i-1];
//        j++;
//    }
//    printf("%s\n", num);
//    return 0;
//}