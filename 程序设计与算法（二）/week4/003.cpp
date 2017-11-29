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
        while (a[j] >= pivot && i < j)
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

    return i;
}

void arrangeRight(int a[], int start, int end, int m)
{
    int pivotIndex = partition(a, start, end);
    if (end - pivotIndex > m)
    {
        arrangeRight(a, pivotIndex + 1, end, m);
    }
    else if (pivotIndex - pivotIndex < m)
    {
        arrangeRight(a, start, pivotIndex, m - end + pivotIndex);
    }
    else
    {
        return;
    }
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
    arrangeRight(a, 0, 5, 3);
    quickSort(a, 3, 5);
    for (int i = 0; i < 6; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}