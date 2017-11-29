#include <iostream>
#include <cmath>

using namespace std;

double a[4];

const double ESP = 1e-6;

bool isZero(double num)
{
    return fabs(num - 0) <= ESP;
}

bool count24(double a[], int n)
{
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    if (n == 1)
    {
        return isZero(a[0] - 24);
    }

    double b[4];
    //int i, j, m, q = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        //cout << "num: " << i << endl;
        for (int j = i + 1; j < n; ++j)
        {
            int q = 0;
            for (int m = 0; m < n; ++m)
            {
                if (m != i && m != j)
                {
                    b[q++] = a[m];
                }
            }
            //cout << "q: " << q << endl;
            b[q] = a[i] + a[j];
            if (count24(b, q + 1))
            {
                return true;
            }

            b[q] = a[i] - a[j];
            if (count24(b, q + 1))
            {
                return true;
            }

            b[q] = a[j] - a[i];
            if (count24(b, q + 1))
            {
                return true;
            }
        
            b[q] = a[i] * a[j];
            if (count24(b, q + 1))
            {
                return true;
            }
        
            if (!isZero(a[i]))
            {
                b[q] = a[j] / a[i];
                if (count24(b, q + 1))
                {
                    return true;
                }
            }

            if (!isZero(a[j]))
            {
                b[q] = a[i] / a[j];
                if (count24(b, q + 1))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    while ((cin >> a[0] >> a[1] >> a[2] >> a[3]) && (a[0] != 0))
    {
        cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
        if (isZero(a[0]))
        {
            return -1;
        }
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