#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

unsigned int my_strlen(const char* str)
{
	assert(*str!=NULL);
	unsigned int count = 0;
	while (*str++ != '\0')
	{
		count++;
	}
	return count;
}

int main()
{
	char arr[] = "abcdefg";
	printf("%d\n", (my_strlen(arr)));
}