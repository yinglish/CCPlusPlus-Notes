#include <iostream>
#include <cstdio>
#include <cstdlib>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while (a % b != 0)
    {
        a = a % b;
        if (a < b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }
    }

    printf("%d", b);
    return 0;
}