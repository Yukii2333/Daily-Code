#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define DATA_NUM 1000
#define NAME_NUM 20
#define SEX_NUM 5
#define ADDR_NUM 30
#define TELE_NUM 12
#define CAP_NUM 3
#define INC_NUM 1

typedef struct PeoInfo
{
	char name[NAME_NUM];
	int age;
	char sex[SEX_NUM];
	char addr[ADDR_NUM];
	char tele[TELE_NUM];
}PeoInfo;


typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;
}Contact;

void init_contact(Contact* pc);//��ʼ��

void add_contact(Contact* pc);//���

void show_contact(const Contact* pc);//չʾ

void del_contact(Contact* pc);//ɾ��

int search_by_name(const Contact* pc, const char* pb);//���Һ���

void search_contact(const Contact* pc);//����

void modify_contact(Contact* pc);//�༭

void sort_contact(Contact* pc);//����

void check_capacity(Contact* pc);

void destroy_contact(Contact* pc);