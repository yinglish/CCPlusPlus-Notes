#include <cstdio>

int main()
{
    long number;
    scanf("%ld", &number);
    while (number != 1)
    {
        if (number % 2)
        {
            printf("%ld*3+1=%ld\n", number, number * 3 + 1);
            number = number * 3 + 1;
        }
        else
        {
            printf("%ld/2=%ld\n", number, number / 2);
            number = number / 2;
        }
    }
    printf("End\n");
    return 0;
}