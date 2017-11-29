#include <iostream>

using namespace std;

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


int main()
{
    int a[] = {9, 3, 2, 6, 10, 18};
    quickSort(a, 0, 0 + sizeof(a) / sizeof(int) - 1);
    cout << "after quick sort: " << endl;
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}