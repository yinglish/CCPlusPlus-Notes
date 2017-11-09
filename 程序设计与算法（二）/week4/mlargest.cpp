#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void ArrangeRight(int a[], int s, int e, int k)
{
    int i = s, j = e;
    int key = a[s];
    while (i != j)
    {
        while (i < j && key <= a[j])
        {
            j--;
        }
        swap(a[i], a[j]);
        while (i < j && key >= a[i])
        {
            i++;
        }
        swap(a[i], a[j]);
    }
    if (k == (e - i))
    {
        return;
    }
    if (k < (e - i))
    {
        ArrangeRight(a, i + 1, e, k);
    }
    else
    {
        ArrangeRight(a, s, i, k - (e - i));
    }
}

void QuickSort(int a[], int s, int e)
{
    int i = s, j = e;
    int key = a[s];
    if (e <= s)
        return;
    
    while (i != j)
    {
        while (key <= a[j] && i < j) // can't be key < a[j]
        {
            j--;
        }
        swap(a[i], a[j]);
        while (key >= a[i] && i < j)
        {
            ++i;
        }
        swap(a[j], a[i]);
    }
    QuickSort(a, s, i - 1);
    QuickSort(a, i + 1, e);
}


int main()
{
    int a[] = {9, 10, 3, 5, 8, 6};
    int size = sizeof(a) / sizeof(int);
    ArrangeRight(a, 0, size - 1, 3);
    QuickSort(a, size - 4, size - 1);
    for (int i = 0; i < 3; ++i)
    {
        cout << a[size - 1 - i] << " ";
    }
    cout << endl;
    return 0;
}