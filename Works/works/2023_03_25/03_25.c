

//leetcode 题解

/*
//思路是数组实现循环队列（由于一次性开辟不存在扩容，数组相比链表更方便）
//结构体包含头（Front）、尾（Rear）、空间大小（k）
//以及用于存储数据的数组或者说指向数组的指针（a）
typedef struct {
    int Front;
    int Rear;
    int k;
    int* a;
} MyCircularQueue;

//创建循环队列
//注意该函数需要返回队列地址
//直接创建对应结构体会在函数结束后销毁，后续会无法访问
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

//判断队列是否为空，为空时Front会与Rear相等，因此以此判断
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    return obj->Front == obj->Rear;
}

//判断是否满员
//逻辑上理解就是Rear在Front后面一个位置
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    return (obj->Rear + 1) % (obj->k + 1) == (obj->Front);
}

//入队
//较为简单，只是需要注意满员不能继续入队
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

//出队
//为空时不能出队
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->Front = (obj->Front + 1) % (obj->k + 1);
    return true;
}

//查看队头成员
int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->a[obj->Front];
}

//查看队尾成员
//由于开辟空间是k+1，除为空外，Rear始终表示没有成员的那一个位置，因此逻辑上要Rear-1
int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->a[(obj->Rear + obj->k) % (obj->k + 1)];
}

//销毁
//老规矩，malloc几次就free几次
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

// 从字符串中删除空格和换行符
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
    printf("输入学生数量：");
    int num = 0;
    scanf("%d", &num);
    int i, j;
    // 循环处理每个学生的作业
    for (i = 1; i <= num; i++) {
        for (j = i + 1; j <= num; j++) {
            // 创建并打开学生作业文件
            char filename1[20], filename2[20];
            snprintf(filename1, sizeof(filename1), "Student%d.txt", i);   // 获取第一个学生作业的文件名
            snprintf(filename2, sizeof(filename2), "Student%d.txt", j);   // 获取第二个学生作业的文件名
            FILE* fp1 = fopen(filename1, "r");   // 打开第一个学生作业文件
            FILE* fp2 = fopen(filename2, "r");   // 打开第二个学生作业文件

            // 如果无法打开文件，退出程序
            if (fp1 == NULL || fp2 == NULL) {
                printf("不能打开文件\n");
                exit(1);
            }

            // 从文件中读取字符串
            char content1[1000], content2[1000];
            fgets(content1, sizeof(content1), fp1);   // 从第一个学生作业文件中读取字符串
            fgets(content2, sizeof(content2), fp2);   // 从第二个学生作业文件中读取字符串

            // 关闭文件
            fclose(fp1);
            fclose(fp2);

            // 从字符串中删除空格和换行符
            remove_space_and_newline(content1);
            remove_space_and_newline(content2);

            // 如果两个学生的作业重复，请打印消息并标记出来
            if (strcmp(content1, content2) == 0) {   // 如果两个学生作业内容相同
                printf("学生%d的作业和学生%d的作业重复\n", i, j);   // 输出重复消息
            }
        }
    }
    return 0;
}