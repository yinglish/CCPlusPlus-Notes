#include <iostream>

using namespace std;

int mergeAndCount(int a[], int start, int mid, int end, int tmp[]);

int mergeSortAndCount(int a[], int start, int end, int tmp[])
{
    int result = 0;
    if (start < end)
    {
        int mid = (start + end) / 2;
        result = mergeSortAndCount(a, start, mid, tmp) + mergeSortAndCount(a, mid + 1, end, tmp) + mergeAndCount(a, start, mid, end, tmp);
    }

    return result;
}

int mergeAndCount(int a[], int start, int mid, int end, int tmp[])
{
    // 先统计跨区间构成的逆序数，再merge
    int result = 0;
    int i = mid;
    int j = end;
    for (; i >= start; --i)
    {
        while (a[j] >= a[i] && j >= mid + 1)
        {
            j--;
        }

        result += j - mid;
    }

    // merge
    i = start;
    j = mid + 1;
    int k = start;
    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            tmp[k++] = a[i++];
        }
        else
        {
            tmp[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        tmp[k++] = a[i++];
    }
    while (j <= end)
    {
        tmp[k++] = a[j++];
    }

    for (int p = start; p < end - start + 1; ++p)
    {
        a[p] = tmp[p];
    }

    return result;
}



int main()
{
    // 结果应该是8，目前不正确，TODO
    int a[] = {2, 6, 3, 4, 5, 1};
    int b[6];
    cout << mergeSortAndCount(a, 0, 5, b) << endl;
    return 0;
}