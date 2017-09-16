#include <iostream>

using namespace std;

typedef int elem_t;

void bubble_sort(elem_t a[], const int start, const int end)
{
    int i, j;
    elem_t tmp;
    int exchange = 0;

    for (int i = start; i < end; ++i)
    {
        exchange = 0;
        for (j = end - 1; j > i; --j)
        {
            if (a[j - 1] > a[j])
            {
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
                exchange = 1;
            }
        }
        if (exchange == 0) return;
    }
}

int main()
{
    return 0;
}