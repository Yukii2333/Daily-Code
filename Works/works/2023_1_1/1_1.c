#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	int n = 0;
	char ch = 0;
	for (ch = getchar(); ch != '\n'; n++);
	//while (getchar() != '\n') n++;
	printf("%d\n", n);
	return 0;
}