#include <iostream>
#include <cmath>

using namespace std;

int a[4];

const double ESP = 1e-6;

bool isZero(double num)
{
    return fabs(num - 0) < ESP;
}

bool count24(int a[], int n)
{
    if (n == 1)
    {
        return isZero(a[0] - 24);
    }

    int b[4];
    int i, j;
    for (i = 0; i < n - 2; ++i)
    {
        b[i] = a[i];
    }

    b[i] = a[n - 2] + a[n - 1];
    if (count24(b, n - 1))
    {
        return true;
    }

    b[i] = a[n - 2] - a[n - 1];
    if (count24(b, n - 1))
    {
        return true;
    }

    b[i] = a[n - 1] * a[n - 2];
    if (count24(b, n - 1))
    {
        return true;
    }

    if (!isZero(b[n - 2]))
    {
        if (count24(b, n - 1))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    while (cin >> a[0] >> a[1] >> a[2] >> a[3] && a[0] != -1)
    {
        if (count24(a, 4))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}