#include <iostream>
#include <cmath>

using namespace std;

#define EPSILON 1e-6

bool IsZero(double x)
{
    return fabs(x) < EPSILON;
}

bool count24(double a[], int n)
{
    double b[5];
    int i, j, k;
    if (n == 0) return false;
    if (n == 1) return IsZero(a[0] - 24);
    for (i = 0; i < n - 1; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            int m = 0;
            for (k = 0; k < n; ++k)
            {
                if (k != i && k != j)
                {
                    b[m++] = a[k];
                }
            }
            b[m] = a[i] + a[j];
            if (count24(b, m + 1))
                return true;
            b[m] = a[i] - a[j];
            if (count24(b, m + 1))
                return true;
            b[m] = a[j] - a[i];
            if (count24(b, m + 1))
                return true;
            b[m] = a[i] * a[j];
            if (count24(b, m + 1))
                return true;
            if (!IsZero(a[i] != 0))
            {
                b[m] = a[j] / a[i];
                if (count24(b, m + 1))
                    return true;
            }
            if (!IsZero(a[j]))
            {
                b[m] = a[i] / a[j];
                if (count24(b, m + 1))
                    return true;
            }
        }
    }
    return false;
}


int main()
{
    double a[5] = {5, 5, 5, 1};
    while (true)
    {
        for (int i = 0; i < 4; ++i)
        {
            cin >> a[i];
        }
        if (IsZero(a[0]))
        {
            break;
        }
        else
        {
            if (count24(a, 4))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}