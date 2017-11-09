#include <cstdio>

int main()
{
    int a, n, i;
    int result = 1;
    scanf("%d %d", &a, &n);
    for (i = 0; i < n; ++i)
    {
        result *= a;
    }

    printf("%d", result);
    return 0;

}