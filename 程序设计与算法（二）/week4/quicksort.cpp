#include <iostream>

using namespace std;


void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
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
    int a[] = {93, 27, 30, 2, 8, 12, 2, 8, 30, 89};
    int size = sizeof(a) / sizeof(int);
    QuickSort(a, 0, size - 1);
    for (int i = 0; i < size; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}