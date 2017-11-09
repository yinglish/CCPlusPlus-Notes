#include <cstdio>

int main()
{
    int l, r, i, leftValue, number = 0;
    scanf("%d %d", &l, &r);
    for (i = l; i <= r; ++i)
    {
        leftValue = i;
        while (leftValue != 0)
        {
            if (leftValue % 10 == 2)
                number++;
            leftValue /= 10;
        }
    }
    printf("%d\n", number);
    return 0;
}