#include <iostream>

using namespace std;

int MergeAndCount(int a[], int s, int m, int e, int tmp[]);
int MergeSortAndCount(int a[], int s, int e, int tmp[]);

int main()
{
    //int a[10] = {13, 27, 19, 2, 8, 12, 2, 8, 30, 89};
    int a[] = {2, 6, 3, 4, 5, 1};
    int b[10];
    int size = sizeof(a) / sizeof(int);
    cout << "The number of inverse pair is: " << MergeSortAndCount(a, 0, size - 1, b) << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

int MergeSortAndCount(int a[], int s, int e, int tmp[])
{
    //int count = 0;
    int p = 0;
    int b = 0;
    int c = 0;
    if (s < e)
    {
        int m = s + (e - s) / 2;
        p = MergeSortAndCount(a, s, m, tmp);
        b = MergeSortAndCount(a, m + 1, e, tmp);
        c = MergeAndCount(a, s, m, e, tmp);
    }
    return p + b + c;
}

int MergeAndCount(int a[], int s, int m, int e, int tmp[])
{
    int count = 0;
    int p0 = 0, p1, p2;

    // counting
    for (p1 = m; p1 >= s; --p1)
    {
        for (p2 = e; p2 >= (m + 1); --p2)
        {
            //cout << a[p1] << " " << a[p2] << endl;
            if (a[p1] > a[p2])
            {
                count += p2 - m;
                break;
                //cout << "here" << endl;
            }
        }
    }

    p1 = s;
    p2 = m + 1;
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


    return count;
}