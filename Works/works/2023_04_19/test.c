#include"fun.h"

void test()
{
	char a[20] = { 0 };
	//输入中缀表达式
	scanf("%s", a);
	
	//临时数组来存储后缀表达式
	char tmp[20] = { 0 };
	//中缀改后缀
	get_postfix(a, tmp);

	printf("%s\n", tmp);

	//根据后缀计算
	int ret = get_result(tmp);

	printf("result = %d\n", ret);
}

int main()
{
	test();
	return 0;
}