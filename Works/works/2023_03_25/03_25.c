

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