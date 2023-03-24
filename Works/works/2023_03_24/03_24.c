

//力扣题解
/*
void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

//向下调整
void AdjustDown(int* a, int k, int parent)
{
    assert(a);
    int child = parent * 2 + 1;
    while (child < k)
    {
        if (child + 1 < k && a[child + 1] > a[child])
        {
            child++;
        }
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
    *returnSize = k;
    //建大堆，模拟Pop一遍
    //升序建大堆，降序建小堆
    for (int i = (arrSize - 2) / 2; i >= 0; i--)
    {
        AdjustDown(arr, arrSize, i);
    }

    //通俗理解就是模拟了堆里的Pop，全部Pop一遍就有序了
    for (int i = arrSize - 1; i > 0; i--)
    {
        Swap(&arr[0], &arr[i]);
        AdjustDown(arr, i, 0);
    }

    return arr;
}

作者：sayounara - d
链接：https ://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/solution/dui-pai-shi-jian-fu-za-du-onlognkong-jia-mqkx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/