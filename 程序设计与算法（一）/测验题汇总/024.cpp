#include <cstdio>
#include <cmath>

int main()
{
    long a;
    int digit;
    bool printZero = false;
    scanf("%ld", &a);
    if (a < 0)
    {
        printf("%c", '-');
    }
    while (a != 0)
    {
        digit = a % 10;
        if (digit == 0 && printZero)
        {
            printf("0");
            //firstZero = false;
        }
        if (digit != 0)
        {
            printZero = true;
            printf("%d", digit >= 0 ? digit : -digit);
            
        }
            
        a /= 10;
    }

    return 0;
}