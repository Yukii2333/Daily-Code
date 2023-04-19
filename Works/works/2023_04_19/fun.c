#include"fun.h"

void get_postfix(char* a, char* tmp)
{
	ST s;
	STInit(&s);
	int i = 0;
	while (*a)
	{
		//读到的值为数字，存入tmp
		if (*a >= '0' && *a <= '9')
		{
			tmp[i++] = *a;
		}
		//为左括号直接入栈
		else if (*a == '(')
		{
			STPush(&s, *a);
		}
		else
		{
			//若栈为空或者栈顶元素为左括号直接入栈
			if (STEmpty(&s) || STTop(&s) == '(')
			{
				STPush(&s, *a);
			}
			else
			{
				char top = STTop(&s);
				//读到右括号
				if (*a == ')')
				{
					//一直出栈直到栈顶元素为左括号
					while (STTop(&s) != '(')
					{
						//出栈的元素依次存入tmp
						tmp[i++] = STTop(&s);
						STPop(&s);
					}
					//最后对栈顶的左括号进行出栈
					STPop(&s);
				}
				//'+','-'无论遇到什么运算符都会先出栈顶元素存入tmp
				//然后将'+','-'入栈
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
					//'*','/'遇见彼此与上面类似
					if (top == '*' || top == '/')
					{
						tmp[i++] = top;
						STPop(&s);
						STPush(&s, *a);
					}
					//'*','/'的优先级高于'+','-'，因而直接入栈
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