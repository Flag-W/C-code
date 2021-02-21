#define _CRT_SECURE_NO_WARNINGS 1 
#define _CRT_SECURE_NO_WARNINGS 1 
#include"contact_dynamic.h"

void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL)
		return ;
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	LoadContact(ps);
}
void CheckCapcity(struct Contact* ps);
void LoadContact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}
	else
	{
		while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))
		{
			CheckCapcity(ps);
			ps->data[ps->size] = tmp;
			ps->size++;
		}
	}
	fclose(pfRead);
	pfRead = NULL;
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
		printf("通讯录为空\n");
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

void CheckCapcity(struct Contact* ps)
{
	if (ps->size == ps->capacity) {
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
			printf("增容失败\n");
	}
}

void AddContact(struct Contact* ps)
{
	CheckCapcity(ps);
	printf("请输入名字:->\n");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄:->\n");
	scanf("%d", &ps->data[ps->size].age);
	printf("请输入性别:->\n");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话:->\n");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址:->\n");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("添加成功\n");
	//检测当前容量
	//if (ps->size == MAX)
	//	printf("通讯录已满,无法增加\n");
	//else
	//{
	//	printf("请输入名字:->\n");
	//	scanf("%s", ps->data[ps->size].name);
	//	printf("请输入年龄:->\n");
	//	scanf("%d", &ps->data[ps->size].age);
	//	printf("请输入性别:->\n");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("请输入电话:->\n");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("请输入地址:->\n");
	//	scanf("%s", ps->data[ps->size].addr);

	//	ps->size++;
	//	printf("添加成功\n");
	//}
}

int FindByName(struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	if (i == ps->size)
		return -1;
}
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字->\n");
	scanf("%s", name);
	//查找删除人的位置
	int pos = FindByName(ps, name);
	if (pos == -1)
		printf("被删除人不存在\n");
	//删除
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];

		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	printf("请输入要查找人的名字\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
		printf("要查找的人不存在\n");
	else
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}

}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入修改人的名字\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
		printf("要修改的人不存在\n");
	else
	{
		printf("请输入名字:->\n");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:->\n");
		scanf("%d", &ps->data[ps->size].age);
		printf("请输入性别:->\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:->\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:->\n");
		scanf("%s", ps->data[ps->size].addr);
		printf("修改完成\n");
	}
}

void SortContact(struct Contact* ps)
{
	//qsort(ps, ps->size, sizeof(ps->data[0]), sort_age);
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		int j = 0;
		for (j = 0; j < ps->size - 1 - i; j++)
		{
			if (ps->data[j].age > ps->data[j + 1].age)
			{
				struct PeoInfo tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}
	}
}

void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact:%s\n", strerror(errno));
		return ;
	}
	else
	{
		int i = 0;
		for (i = 0; i < ps->size; i++)
			fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}

