#include <cstdio>

int main()
{
    int n, x, y, result;
    scanf("%d %d %d", &n, &x, &y);
    if (y / x <= 10)
    {
        if (y % x)
        result = n - (y / x + 1);
    else
        result = n - y / x;
    printf("%d\n", result);

    return 0;
    }
    else 
        printf("%d", 0);
    
}