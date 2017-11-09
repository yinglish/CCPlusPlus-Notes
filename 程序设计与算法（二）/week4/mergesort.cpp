#include <iostream>

using namespace std;

void Merge(int a[], int s, int m, int e, int tmp[]);
void MergeSort(int a[], int s, int e, int tmp[]);

int main()
{
    int a[10] = {13, 27, 19, 2, 8, 12, 2, 8, 30, 89};
    int b[10];
    int size = sizeof(a) / sizeof(int);
    MergeSort(a, 0, size - 1, b);
    for (int i = 0; i < size; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

void MergeSort(int a[], int s, int e, int tmp[])
{
    if (s < e)
    {
        int m = s + (e - s) / 2;
        MergeSort(a, s, m, tmp);
        MergeSort(a, m + 1, e, tmp);
        Merge(a, s, m, e, tmp);
    }
}

void Merge(int a[], int s, int m, int e, int tmp[])
{
    int p0 = 0;
    int p1 = s;
    int p2 = m + 1;
    while (p1 < m + 1 && p2 < e + 1)
    {
        if (a[p1] < a[p2])
        {
            tmp[p0++] = a[p1++];
        }
        else
        {
            tmp[p0++] = a[p2++];
        }
    }
    while (p1 < m + 1)
    {
        tmp[p0++] = a[p1++];
    }
    while (p2 < e + 1)
    {
        tmp[p0++] = a[p2++];
    }

    p0 = 0;
    p1 = s;
    while (p1 < e + 1)
    {
        a[p1++] = tmp[p0++];
    }
}