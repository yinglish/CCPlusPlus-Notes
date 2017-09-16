#include <iostream>

using namespace std;

typedef int elem_t;

void select_sort(elem_t a[], const int start, const int end)
{
    int i, j;
    elem_t tmpMin, tmp;
    
    for (i = start; i < end - 1; ++i)
    {
        tmpMin = a[i];
        for (j = i + 1; j < end; ++j)
        {
            if (a[j] < tmpMin)
            {
                tmp = a[j];
                a[j] = tmpMin;
                tmpMin = tmp;
            }
        }
        a[i] = tmpMin;
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
    elem_t a[] = {3, 1, 6, 5, 9, 2};
    select_sort(a, 0, 6);
    print(a, 6);
    return 0;
}