#include <iostream>

using namespace std;

typedef int elem_t;

int get_left(int i)
{
    return 2 * i;
}

int get_right(int i)
{
    return 2 * i + 1;
}

// 注意不使用下标为0的元素
void heapify(elem_t a[], int i, int n)
{
    int tmp_swap;
    int left = get_left(i);
    int right = get_right(i);
    if (right <= n)
    {
        if (a[right] > a[i])
        {
            tmp_swap = a[i];
            a[i] = a[right];
            a[right] = tmp_swap;
            heapify(a, left, n);
        }
    }

    if (left <= n)
    {
        if (a[left] > a[i])
        {
            tmp_swap = a[i];
            a[i] = a[left];
            a[left] = tmp_swap;
            heapify(a, right, n);
        }
    }
}

void built_heap(elem_t a[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(a, i, n);
    }
}

elem_t heap_max(elem_t a[])
{
    return a[1];
}

void heap_sort(elem_t a[], int n)
{
    build_heap(a, n);
    for (int i = n - 1; i > 1; ++i)
    {
        int tmp = a[i];
        a[i] = a[1];
        a[1] = tmp;
        heapify(a, 1, i);
    }
}


int main()
{
    return 0;
}