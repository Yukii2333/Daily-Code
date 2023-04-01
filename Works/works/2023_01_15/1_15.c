#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



//int my_atoi(const char* p)
//{
//	int result = 0;
//	int i = 0;
//	int tmp1 = 0;
//	int tmp2 = 0;
//	while (*(p + i) >= 48 && *(p + i) <= 57)
//	{
//		tmp1 = (int)*(p + i) - 48;
//		tmp1 *= tmp2;
//		tmp
//	}
//}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

enum STATE
{
    VALID,//合法
    INVALID//非法
};
enum STATE state = INVALID;

int my_atoi(char* str)
{
    int flag = 1;
    long long ret = 0;
    assert(str != NULL);//空指针
    if (*str == '\0')//处理空字符串
        return 0;//返回结果为非法
    while (isspace(*str))//处理空格
    {
        str++;
        if (*str == '\0')
            return 0;//字符串只有空格
    }
    if (*str == '+')//+-号
        str++;
    if (*str == '-')
    {
        flag = -flag;
        str++;
    }
    while (*str)//字符串处理
    {
        if (isdigit(*str))
        {
            ret = ret * 10 + (*str - '0') * flag;
            if ((ret > INT_MAX) || (ret < INT_MIN))//溢出
            {
                state = VALID;
                return INT_MIN;
            }
        }
        else//非数字字符
        {
            state = VALID;
            return (int)ret;//返回结果为前面的数字
        }
        str++;
    }
    state = VALID;
    return (int)ret;
}


int main()
{
	char arr[] = "998g";
	int ret = my_atoi(arr);
    printf("%d\n", ret);
	return 0;
}