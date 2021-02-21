#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>


void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

int sort_int(void* e1, void* e2)
{
	return *((int*)e1) - *((int*)e2);
}

void q_sort(void* base, int sz, int width, int  (*cmp)(void* e1,void* e2))
{
	int i=0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp(((char*)base + j * width), ((char*)base + (j + 1) * width)) > 0)
			{
				swap(((char*)base+j*width),((char*)base+(j+1)*width),width);
			}
		}
	}
}
struct stu {
	char name[20];
	int age;

};

int sort_age(void* e1, void* e2)
{
	return ((struct stu*)e1)->age- ((struct stu*)e2)->age;
}

int main()
{
	struct stu s[3] = { {"zhangsan",50},{"lisi",2},{"wangwu",0} };
	int i = 0;
	int arr[] = { 3,5,1,2,4,9,8,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int sz1 = sizeof(s) / sizeof(s[0]);
	//q_sort(arr, sz, sizeof(arr[0]), sort_int);
	q_sort(s, sz1, sizeof(s[0]), sort_age);
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
	return;
}