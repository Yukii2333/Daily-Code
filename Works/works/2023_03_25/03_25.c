

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