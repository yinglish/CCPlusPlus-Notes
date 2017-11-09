#include <cstdio>

int main()
{
    int i, h7, h9, t7, t9, o7, o9, number;
    for (i = 64; i <= 285; ++i)
    {
        number = i;
        o7 = number % 7;
        number /= 7;
        t7 = number % 7;
        number /= 7;
        h7 = number % 7;
        number = i;
        o9 = number % 9;
        number /= 9;
        t9 = number % 9;
        number /= 9;
        h9 = number % 9;

        if (h7 == o9 && t7 == t9 && o7 == h9)
        {
            printf("%d\n", i);
            printf("%d%d%d\n", h7, t7, o7);
            printf("%d%d%d\n", h9, t9, o9);
        }
    }
    return 0;
}