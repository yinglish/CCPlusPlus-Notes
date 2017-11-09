#include <cstdio>

int main()
{
    int numbers, i, in, small = 1001;
    int big = -1;
    scanf("%d", &numbers);
    for (i = 0; i < numbers; ++i)
    {
        scanf("%d", &in);
        if (in < small)
            small = in;
        if (in > big)
            big = in;
    }

    printf("%d", big - small);
    return 0;
}