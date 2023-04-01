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
    VALID,//�Ϸ�
    INVALID//�Ƿ�
};
enum STATE state = INVALID;

int my_atoi(char* str)
{
    int flag = 1;
    long long ret = 0;
    assert(str != NULL);//��ָ��
    if (*str == '\0')//������ַ���
        return 0;//���ؽ��Ϊ�Ƿ�
    while (isspace(*str))//����ո�
    {
        str++;
        if (*str == '\0')
            return 0;//�ַ���ֻ�пո�
    }
    if (*str == '+')//+-��
        str++;
    if (*str == '-')
    {
        flag = -flag;
        str++;
    }
    while (*str)//�ַ�������
    {
        if (isdigit(*str))
        {
            ret = ret * 10 + (*str - '0') * flag;
            if ((ret > INT_MAX) || (ret < INT_MIN))//���
            {
                state = VALID;
                return INT_MIN;
            }
        }
        else//�������ַ�
        {
            state = VALID;
            return (int)ret;//���ؽ��Ϊǰ�������
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