#include <cstdio>

int main()
{
    int m, n, x;
    int leftM;
    scanf("%d %d %d", &m, &n, &x);
    while (x * n >= m && m >= n)
    {
        if (m % n)
            x = x - m / n - 1;
        else
            x = x - m / n;
        leftM = m;
        n += leftM / n;
    }

    printf("%d\n", n);

    return 0;
}