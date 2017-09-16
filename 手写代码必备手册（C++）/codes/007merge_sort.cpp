#include <iostream>

using namespace std;

typedef int elem_t;

static void merge(elem_t a[], elem_t tmp[], const int start, const int mid, const int end)
{
    int i, j, k;
    for (i = start; i < end; ++i)
    {
        tmp[i] = a[i];
    }

    for (i = start, j = mid, k = start; i < mid && j < end;)
    {
        if (tmp[i] < tmp[j])
        {
            a[k++] = tmp[i++];
        }
        else
        {
            a[k++] = tmp[j++];
        }
    }

    while (i < mid)
    {
        a[k++] = tmp[i++];
    }

    while (j < end)
    {
        a[k++] = tmp[j++];
    }
}

void merge_sort(elem_t a[], elem_t tmp[], const int start, const int end)
{
    if (start < end - 1)
    {
        const int mid = (start + end) / 2;
        merge_sort(a, tmp, start, mid);
        merge_sort(a, tmp, mid, end);
        merge(a, tmp, start, mid, end);
    }
}

void print(elem_t a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    elem_t a[] = {3, 8, 5, 1, 9, 23, 18};
    elem_t tmp[7]; 
    cout << "before sort: " << endl;
    print(a, 7);
    cout << "after sort: " << endl;
    merge_sort(a, tmp, 0, 7);
    print(a, 7);
    return 0;
}