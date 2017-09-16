#include <iostream>

using namespace std;

typedef int elem_t;

void straight_insertion_sort(elem_t a[], const int start, const int end)
{
    elem_t tmp;
    int i, j;

    for (int i = start + 1; i <= end; ++i)
    {
        tmp = a[i];
        for (j = i - 1; tmp < a[j] && j >= start; --j)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp;
    }
}

void binary_insertion_sort(elem_t a[], const int start, const int end)
{
    elem_t tmp;
    int i, j, left, right, mid;

    for (i = start + 1; i <= end; ++i)
    {
        tmp = a[i];
        left = start;
        right = i - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (tmp < a[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        for (j = i - 1; j >= left; --j)
        {
            a[j + 1] = a[j];
        }
        a[left] = tmp;
        
    }
}

void print(elem_t a[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}


static void shell_insert(elem_t a[], const int start, const int end, const int gap)
{
    elem_t tmp;
    int i, j;
    for (i = start + gap; i <= end; ++i)
    {
        tmp = a[i];
        for (j = i - gap; tmp < a[j] && j >= start; j-= gap)
        {
            a[j + gap] = a[j];
        }
        a[j + gap] = tmp;
    }
}

void shell_sort(elem_t a[], const int start, const int end)
{
    int gap = end - start;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        shell_insert(a, start, end, gap);
    }
}

int main()
{
    cout << "test straight insertion sort: " << endl;
    int a1[] = {3, 4, 13, 7, 14, 12};
    cout << "befor sorting: " << endl;
    print(a1, 6);
    cout << "after sort: " << endl;
    straight_insertion_sort(a1, 0, 5);
    print(a1, 6);
    cout << "-------------------" << endl;
    cout << "test straight insertion sort: " << endl;
    int b1[] = {3, 4, 13, 7, 14, 12};
    cout << "befor sorting: " << endl;
    print(b1, 6);
    cout << "after sort: " << endl;
    binary_insertion_sort(b1, 0, 5);
    print(b1, 6);

    cout << "-------------------" << endl;
    cout << "test shell sort: " << endl;
    int c1[] = {3, 4, 13, 7, 14, 12};
    cout << "befor sorting: " << endl;
    print(c1, 6);
    cout << "after sort: " << endl;
    shell_sort(c1, 0, 5);
    print(c1, 6);


    return 0;
}