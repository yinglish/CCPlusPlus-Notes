#include <iostream>

using namespace std;


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

    for (int j = start; j < end -start + 1; ++j)
    {
        a[j] = tmp[j];
    }
}


int main()
{
    int a[] = {3, 9, 21, 2, 9};
    int tmp[5];
    mergeSort(a, 0, 4, tmp);
    cout << "after mergesort: " << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}