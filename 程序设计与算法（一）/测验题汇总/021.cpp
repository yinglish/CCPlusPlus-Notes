#include <cstdio>

int main()
{
    int numbers, i, total, good;
    double x, y;
    scanf("%d", &numbers);
    scanf("%d %d", &total, &good);
    x = (double)good / total;
    for (i = 0; i < numbers - 1; ++i)
    {
        scanf("%d %d", &total, &good);
        y = (double)good / total;
        if (x - y > 0.05)
            printf("worse\n");
        else if (y - x > 0.05)
            printf("better\n");
        else
            printf("same\n");
    }
    return 0;
}