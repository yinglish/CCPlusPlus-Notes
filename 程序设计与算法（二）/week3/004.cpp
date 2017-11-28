#include <iostream>
#include <cmath>

using namespace std;

int a[4];

const double ESP = 1e-6;

bool isZero(double num)
{
    return fabs(num - 0) < ESP;
}

double count24(int a[], int n)
{
    if (n == 1)
    {
        return isZero(a[0]);
    }

    int b[4];
    int i, j;
    for (i = 0; i < n - 2; ++i)
    {
        b[i] = a[i];
    }




}

int main()
{
    return 0;
}