#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

int search_by_name(const Contact* pc, const char* pb)
{
	assert(pc);
	assert(pb);
	int target = 0;
	int tmp = 0;
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		tmp = strcmp(pc->data[i].name, pb);
		if (tmp == 0)
		{
			target = i;
			break;
		}
	}
	if (tmp == 0)
	{
		return target;
	}
	else
	{
		return -1;
	}
}

void check_capacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = realloc(pc->data, (pc->capacity + INC_NUM) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			perror("check_capacity::realloc");
			return;
		}
		pc->data = ptr;
		pc->capacity += INC_NUM;
		printf("已扩容\n");
	}
}

void load_contact(Contact* pc)
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("load_contact::fopen");
		return;
	}
	PeoInfo tmp = { 0 };
	int i = 0;
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		check_capacity(pc);
		pc->data[i] = tmp;
		pc->sz++;
		i++;
	}
	printf("加载通讯录成功\n");
	fclose(pf);
	pf = NULL; 
}

void init_contact(Contact* pc)//动态
{
	assert(pc);
	pc->sz = 0;
	PeoInfo* ptr = (PeoInfo*)calloc(CAP_NUM, sizeof(PeoInfo));
	if (ptr == NULL)
	{
		perror("init_contact::calloc");
		return;
	}
	pc->data = ptr;
	pc->capacity = CAP_NUM;
	load_contact(pc);
}

//void init_contact(Contact* pc)//静态
//{
//	assert(pc);
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

void add_contact(Contact* pc)
{
	assert(pc);
	check_capacity(pc);
	printf("请输入名字：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	pc->sz++;
}

//void add_contact(Contact* pc)
//{
//	assert(pc);
//	if (pc->sz == DATA_NUM)
//	{
//		printf("通讯录满，无法添加\n");
//		return;
//	}
//	printf("请输入名字：");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入年龄：");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入性别：");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入地址：");
//	scanf("%s", pc->data[pc->sz].addr);
//	printf("请输入电话：");
//	scanf("%s", pc->data[pc->sz].tele);
//	pc->sz++;
//}

void show_contact(const Contact* pc)
{
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "名字","年龄","性别","地址","电话");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[i].name, 
									   pc->data[i].age,
									   pc->data[i].sex, 
									   pc->data[i].addr, 
									   pc->data[i].tele);
	}
}

void del_contact(Contact* pc)
{
	assert(pc);
	char name[NAME_NUM] = { 0 };
	if (pc->sz == 0)
	{
		printf("无联系人，无法删除\n");
		return;
	}
	printf("输入要删除人姓名：");
	scanf("%s", name);
	int i = 0;
	int del = search_by_name(pc, name);
	if (del != -1)
	{
		printf("已找到，是否确认删除？1.Y  any.N\n");
		int set = 0;
		scanf("%d", set);
		if (set == 1)//实质是用末尾覆盖目标然后总数减一来实现删除
		{
			pc->data[del] = pc->data[pc->sz-1];
			pc->sz--;
			printf("已删除\n");
		}
		else
		{
			printf("已取消\n");
			return;
		}
	}
	else
	{
		printf("未找到，请重新查找\n");
		return;
	}
}

void search_contact(const Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("请输入姓名：");
	scanf("%s", name);
	int ret = search_by_name(pc, name);
	if (ret != -1)
	{
		printf("找到了\n");
		printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "名字", "年龄", "性别", "地址", "电话");
		printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].sex,
			pc->data[ret].addr,
			pc->data[ret].tele);
	}
	else
	{
		printf("未找到，请确认姓名是否正确\n");
		return;
	}
}

void modify_contact(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("请输入姓名：");
	int ret = search_by_name(pc, name);
	if (ret == -1)
	{
		printf("未找到，请确认姓名是否正确");
		return;
	}
	else
	{
		printf("找到了\n");
		printf("请输入名字：");
		scanf("%s", pc->data[ret].name);
		printf("请输入年龄：");
		scanf("%d", &(pc->data[ret].age));
		printf("请输入性别：");
		scanf("%s", pc->data[ret].sex);
		printf("请输入地址：");
		scanf("%s", pc->data[ret].addr);
		printf("请输入电话：");
		scanf("%s", pc->data[ret].tele);
		printf("已修改\n");
	}
}

void cmp_by_age(const void* e1, const void* e2)
{
	return (((Contact*)e1)->data->age - ((Contact*)e2)->data->age);
}

void sort_contact(Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_by_age);
	printf("排序完成\n");
}

void save_contact(Contact* pc)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)//判断是否打开成功
	{
		perror("save_contact::fopen");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}
	printf("保存成功\n");
	fclose(pf);
	pf = NULL;
}

void destroy_contact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}
