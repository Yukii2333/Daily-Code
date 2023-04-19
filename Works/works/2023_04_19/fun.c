#include"fun.h"

void get_postfix(char* a, char* tmp)
{
	ST s;
	STInit(&s);
	int i = 0;
	while (*a)
	{
		//������ֵΪ���֣�����tmp
		if (*a >= '0' && *a <= '9')
		{
			tmp[i++] = *a;
		}
		//Ϊ������ֱ����ջ
		else if (*a == '(')
		{
			STPush(&s, *a);
		}
		else
		{
			//��ջΪ�ջ���ջ��Ԫ��Ϊ������ֱ����ջ
			if (STEmpty(&s) || STTop(&s) == '(')
			{
				STPush(&s, *a);
			}
			else
			{
				char top = STTop(&s);
				//����������
				if (*a == ')')
				{
					//һֱ��ջֱ��ջ��Ԫ��Ϊ������
					while (STTop(&s) != '(')
					{
						//��ջ��Ԫ�����δ���tmp
						tmp[i++] = STTop(&s);
						STPop(&s);
					}
					//����ջ���������Ž��г�ջ
					STPop(&s);
				}
				//'+','-'��������ʲô����������ȳ�ջ��Ԫ�ش���tmp
				//Ȼ��'+','-'��ջ
				else if (*a == '+' || *a == '-')
				{
					if (top == '+' || top == '-' || top == '*' || top == '/')
					{
						tmp[i++] = top;
						STPop(&s);
						STPush(&s, *a);
					}
				}
				else if (*a == '*' || *a == '/')
				{
					//'*','/'�����˴�����������
					if (top == '*' || top == '/')
					{
						tmp[i++] = top;
						STPop(&s);
						STPush(&s, *a);
					}
					//'*','/'�����ȼ�����'+','-'�����ֱ����ջ
					if (top == '+' || top == '-')
					{
						STPush(&s, *a);
					}
				}
			}
		}
		a++;
	}
	while (!STEmpty(&s))
	{
		tmp[i++] = STTop(&s);
		STPop(&s);
	}
	STDestroy(&s);
}

int get_result(char* a)
{
	ST s;
	STInit(&s);
	while (*a)
	{
		if (*a >= '0' && *a <= '9')
		{
			STPush(&s, (*a-'0'));
		}
		else
		{
			char fun = *a;
			int num2 = STTop(&s);
			STPop(&s);
			int num1 = STTop(&s);
			STPop(&s);
			if (fun == '+')
			{
				STPush(&s, num1 + num2);
			}
			else if (fun == '-')
			{
				STPush(&s, num1 - num2);
			}
			else if (fun == '*')
			{
				STPush(&s, num1 * num2);
			}
			else if (fun == '/')
			{
				STPush(&s, num1 / num2);
			}
		}
		a++;
	}
	int result = STTop(&s);
	STPop(&s);
	STDestroy(&s);
	return result;
}