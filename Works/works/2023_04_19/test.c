#include"fun.h"

void test()
{
	char a[20] = { 0 };
	//������׺���ʽ
	scanf("%s", a);
	
	//��ʱ�������洢��׺���ʽ
	char tmp[20] = { 0 };
	//��׺�ĺ�׺
	get_postfix(a, tmp);

	printf("%s\n", tmp);

	//���ݺ�׺����
	int ret = get_result(tmp);

	printf("result = %d\n", ret);
}

int main()
{
	test();
	return 0;
}