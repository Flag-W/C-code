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
		printf("ͨѶ¼Ϊ��\n");
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
			printf("���ݳɹ�\n");
		}
		else
			printf("����ʧ��\n");
	}
}

void AddContact(struct Contact* ps)
{
	CheckCapcity(ps);
	printf("����������:->\n");
	scanf("%s", ps->data[ps->size].name);
	printf("����������:->\n");
	scanf("%d", &ps->data[ps->size].age);
	printf("�������Ա�:->\n");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰:->\n");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ:->\n");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("��ӳɹ�\n");
	//��⵱ǰ����
	//if (ps->size == MAX)
	//	printf("ͨѶ¼����,�޷�����\n");
	//else
	//{
	//	printf("����������:->\n");
	//	scanf("%s", ps->data[ps->size].name);
	//	printf("����������:->\n");
	//	scanf("%d", &ps->data[ps->size].age);
	//	printf("�������Ա�:->\n");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("������绰:->\n");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("�������ַ:->\n");
	//	scanf("%s", ps->data[ps->size].addr);

	//	ps->size++;
	//	printf("��ӳɹ�\n");
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
	printf("������Ҫɾ���˵�����->\n");
	scanf("%s", name);
	//����ɾ���˵�λ��
	int pos = FindByName(ps, name);
	if (pos == -1)
		printf("��ɾ���˲�����\n");
	//ɾ��
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];

		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	printf("������Ҫ�����˵�����\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
		printf("Ҫ���ҵ��˲�����\n");
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
	printf("�������޸��˵�����\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
		printf("Ҫ�޸ĵ��˲�����\n");
	else
	{
		printf("����������:->\n");
		scanf("%s", ps->data[ps->size].name);
		printf("����������:->\n");
		scanf("%d", &ps->data[ps->size].age);
		printf("�������Ա�:->\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰:->\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ:->\n");
		scanf("%s", ps->data[ps->size].addr);
		printf("�޸����\n");
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

