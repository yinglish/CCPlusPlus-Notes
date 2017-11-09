#include <cstdio>

int main()
{
    int numbers, in, i, sum = 0;
    scanf("%d", &numbers);
    for (i = 0; i < numbers; ++i)
    {
        scanf("%d", &in);
        sum += in;
    }
    printf("%d %.5f", sum, (double)sum / numbers); // 之前写的float，一直无法通过

    return 0;
}