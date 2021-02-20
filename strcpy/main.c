#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>

char* my_strcat(char* p1, const char* p2)
{
	assert(p1 && p2);
	char* ret = p1;
	while (*p1++)
	{
		;
	}
	p1--;
	while (*p1++ = *p2++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[30] = "hello ";
	char arr2[] = "world";
	char* ret = my_strcat(arr1, arr2);
	printf("%s", ret);
	return 0;
}