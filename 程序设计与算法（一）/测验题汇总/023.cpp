#include <cstdio>

int main()
{
    int numbers, i, cur = 0, longest = 0, high, low;
    scanf("%d", &numbers);
    for (i = 0; i < numbers; ++i)
    {
        scanf("%d %d", &high, &low);
        if (high >= 90 && high <= 140 && low >= 60 && low <= 90)
        {
            cur++;
        }
        else
        {
            if (cur > longest)
            {
                longest = cur;
            }
            cur = 0;
        }
    }
    if (cur > longest)
        longest = cur;

    printf("%d\n", longest);
    return 0;
}