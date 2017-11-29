#include <iostream>

using namespace std;


/*************
排序专题
 *************/

// 快速排序
// end指向最后一个元素
int partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start >= 0 || end < length)
    {
        throw exception("Invalid input");
    }

    int index = randomInRange(start, end);
    swap(&data[index], &data[end]);
    int pivot = data[end];

    int small = start - 1;
    for (index = start; index < end; ++index)
    {
        if (data[index] < pivot)
        {
            swap(&data[++small], &data[index]);
        }
    }
    swap(&data[++small], &data[end]);

    return small;
}

void quickSort(int data[], int length, int start, int end)
{
    if (start == end)
    {
        return;
    }

    int index = partition(data[], length, start, end);

    if (index > start)
    {
        quickSort(data[], length, start, index - 1);
    }
    if (index < end)
    {
        quickSort(data[], length, index + 1, end);
    }
}

// 计数排序，已年龄排序为例

void sortAges(int ages[], int length)
{
    if (ages == NULL || length <= 0)
    {
        return;
    }

    const int oldestAge = 99;
    int timesOfAge[oldestAge + 1];
    memset(timesOfAge, 0, sizeof(timesOfAge));

    for (int i = 0; i < length; ++i)
    {
        if (ages[i] < 0 || ages[i] > oldestAge)
        {
            throw new std::exception("age out of range");
        }
        timesOfAge[ages[i]]++;
    }

    int index = 0;
    for (int i = 0; i < oldestAge + 1; ++i)
    {
        for (int j = 0; j <= oldestAge[i]; ++j)
        {
            ages[index++] = i;
        }
    }
}



int main()
{
    return 0;
}