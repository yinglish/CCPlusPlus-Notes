#include <iostream>
#include <cstdio>

using namespace std;

// m: apple, n: plate
int f(int m, int n)
{
    if (n > m) return f(m, m);
    if (m == 0) return 1;
    if (n <= 0) return 0;

    return f(m, n - 1) + f(m - n, n);
}


int main()
{
    int t;
    int apples, plates;
    cin >> t;
    while(t--)
    {
        cin >> apples >> plates;
        printf("%d\n", f(apples, plates));
    }
    return 0;
}