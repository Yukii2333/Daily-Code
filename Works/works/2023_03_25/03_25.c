

//leetcode ���

/*
//˼·������ʵ��ѭ�����У�����һ���Կ��ٲ��������ݣ����������������㣩
//�ṹ�����ͷ��Front����β��Rear�����ռ��С��k��
//�Լ����ڴ洢���ݵ��������˵ָ�������ָ�루a��
typedef struct {
    int Front;
    int Rear;
    int k;
    int* a;
} MyCircularQueue;

//����ѭ������
//ע��ú�����Ҫ���ض��е�ַ
//ֱ�Ӵ�����Ӧ�ṹ����ں������������٣��������޷�����
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* Que;
    Que = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (Que == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    Que->a = (int*)malloc(sizeof(int) * (k + 1));
    if (Que->a == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    Que->Front = 0;
    Que->Rear = 0;
    Que->k = k;
    return Que;
}

//�ж϶����Ƿ�Ϊ�գ�Ϊ��ʱFront����Rear��ȣ�����Դ��ж�
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    return obj->Front == obj->Rear;
}

//�ж��Ƿ���Ա
//�߼���������Rear��Front����һ��λ��
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    return (obj->Rear + 1) % (obj->k + 1) == (obj->Front);
}

//���
//��Ϊ�򵥣�ֻ����Ҫע����Ա���ܼ������
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->a[obj->Rear] = value;
    obj->Rear = (obj->Rear + 1) % (obj->k + 1);
    return true;
}

//����
//Ϊ��ʱ���ܳ���
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->Front = (obj->Front + 1) % (obj->k + 1);
    return true;
}

//�鿴��ͷ��Ա
int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->a[obj->Front];
}

//�鿴��β��Ա
//���ڿ��ٿռ���k+1����Ϊ���⣬Rearʼ�ձ�ʾû�г�Ա����һ��λ�ã�����߼���ҪRear-1
int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->a[(obj->Rear + obj->k) % (obj->k + 1)];
}

//����
//�Ϲ�أ�malloc���ξ�free����
void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    free(obj->a);
    free(obj);
    obj = NULL;
}

*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ���ַ�����ɾ���ո�ͻ��з�
void remove_space_and_newline(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i]) && str[i] != '\r' && str[i] != '\n') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

int main() {
    printf("����ѧ��������");
    int num = 0;
    scanf("%d", &num);
    int i, j;
    // ѭ������ÿ��ѧ������ҵ
    for (i = 1; i <= num; i++) {
        for (j = i + 1; j <= num; j++) {
            // ��������ѧ����ҵ�ļ�
            char filename1[20], filename2[20];
            snprintf(filename1, sizeof(filename1), "Student%d.txt", i);   // ��ȡ��һ��ѧ����ҵ���ļ���
            snprintf(filename2, sizeof(filename2), "Student%d.txt", j);   // ��ȡ�ڶ���ѧ����ҵ���ļ���
            FILE* fp1 = fopen(filename1, "r");   // �򿪵�һ��ѧ����ҵ�ļ�
            FILE* fp2 = fopen(filename2, "r");   // �򿪵ڶ���ѧ����ҵ�ļ�

            // ����޷����ļ����˳�����
            if (fp1 == NULL || fp2 == NULL) {
                printf("���ܴ��ļ�\n");
                exit(1);
            }

            // ���ļ��ж�ȡ�ַ���
            char content1[1000], content2[1000];
            fgets(content1, sizeof(content1), fp1);   // �ӵ�һ��ѧ����ҵ�ļ��ж�ȡ�ַ���
            fgets(content2, sizeof(content2), fp2);   // �ӵڶ���ѧ����ҵ�ļ��ж�ȡ�ַ���

            // �ر��ļ�
            fclose(fp1);
            fclose(fp2);

            // ���ַ�����ɾ���ո�ͻ��з�
            remove_space_and_newline(content1);
            remove_space_and_newline(content2);

            // �������ѧ������ҵ�ظ������ӡ��Ϣ����ǳ���
            if (strcmp(content1, content2) == 0) {   // �������ѧ����ҵ������ͬ
                printf("ѧ��%d����ҵ��ѧ��%d����ҵ�ظ�\n", i, j);   // ����ظ���Ϣ
            }
        }
    }
    return 0;
}