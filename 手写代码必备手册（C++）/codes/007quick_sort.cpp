#include <iostream>

using namespace std;

typedef int elem_t;

int partition(elem_t a[], const int start, const int end)
{
    int i = start - 1, j;
    elem_t piviot = a[end - 1];
    cout << "piviot: " << piviot << endl;
    elem_t tmp;

    for (j = start; j < end - 1; ++j)
    {
        if (a[j] <= piviot)
        {
            tmp = a[i + 1];
            a[i + 1] = a[j];
            a[j] = tmp;
            //j++;
            i++;
            cout << "i: " << i << endl;
        }
        else
        {  
            //j++;
        }
    }
    tmp = a[i + 1];
    a[i + 1] = a[end - 1];
    a[end - 1] = tmp;

    return i + 1;
}

int partition2(elem_t a[], const int start, const int end)
{
    int i, j;
    i = start;
    j = end - 1;
    elem_t piviot = a[i];

    while (i < j)
    {
        while (j > i && a[j] >= piviot) --j;
        a[i] = a[j];
        while (i < j && a[i] <= piviot) ++i;
        a[j] = a[i];
    }
    a[i] = piviot;
    return i;
}

void print(elem_t a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void quick_sort(elem_t a[], const int start, const int end)
{
    if (start < end - 1)
    {
        const int piviot_pos = partition(a, start, end);
        quick_sort(a, start, piviot_pos);
        quick_sort(a, piviot_pos + 1, end);
    }
}

int main()
{
    elem_t a[] = {6, 7, 3, 4 , 9, 5};
    elem_t b[] = {6, 7, 3, 4 , 9, 5};

    //cout << partition(a, 0, 6) << endl;
    //print(a, 6);
    quick_sort(a, 0, 6);
    print(a, 6);
    cout << partition2(b, 0, 6) << endl;
    print(b, 6);

    return 0;
}