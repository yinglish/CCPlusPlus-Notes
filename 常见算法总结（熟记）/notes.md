## 常见算法总结

* 以下算法必须理解后熟记下来，能够快速的手写出来，适合笔试，机试，面试前复习

### 排序相关算法

* 归并
  * 注意，适合快速完成，手写或机试均可，如真实应用使用库函数或改进
  * 为了方便，使用全局数组即可，不需要自己动态开辟临时空间，还是使用全局数组

```C++
void merge(int a[], int start, int mid, int end, int tmp[]);

void mergeSort(int a[], int start, int end, int tmp[])
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid, tmp);
        mergeSort(a, mid + 1, end, tmp);
        merge(a, start, mid, end, tmp);
    }
}

void merge(int a[], int start, int mid, int end, int tmp[])
{
    int left = start;
    int right = mid + 1;
    int i = start;

    while (left <= mid && right <= end)
    {
        if (a[left] <= a[right])
        {
            tmp[i++] = a[left++];
        }
        else
        {
            tmp[i++] = a[right++];
        }
    }

    while (left <= mid)
    {
        tmp[i++] = a[left++];
    }

    while (right <= end)
    {
        tmp[i++] = a[right++];
    }

    // 注意j的起始位置
    for (int j = start; j < end -start + 1; ++j)
    {
        a[j] = tmp[j];
    }
}
```

* 快速排序
  * 选主元，分数组
  * 最坏情况分析，解决方法：随机化快排
```C++
void mySwap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int a[], int start, int end)
{
    int i = start;
    int j = end;
    int pivot = a[start];

    while (i < j)
    {
        while (a[j] >= pivot && i < j) // 注意此处必须有等号以及 i < j
        {
            j--;
        }

        mySwap(a[i], a[j]);

        while (a[i] <= pivot && i < j)
        {
            i++;
        }
        mySwap(a[i], a[j]);
    }
    cout << "pivot index is: " << i << endl;

    return i;
}

void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partition(a, start, end);
        quickSort(a, start, pivotIndex - 1); // piviotIndex在两边都不能出现
        quickSort(a, pivotIndex + 1, end);
    }
}
```