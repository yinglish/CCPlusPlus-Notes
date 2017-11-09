#include <iostream>
#include <cstdio>

int main()
{
    int results[4] = {0};
    int numbers, value;
    scanf("%d", &numbers);
    for (int i = 0; i < numbers; ++i)
    {
        scanf("%d", &value);
        if (value >= 0 && value <= 18)
        {
            results[0]++;
        }
        else if (value >=19 && value <= 35)
        {
            results[1]++;
        }
        else if (value >= 36 && value <= 60)
        {
            results[2]++;
        }
        else if (value >= 61)
        {
            results[3]++;
        }
    }
    int sum = results[0] + results[1] + results[2] + results[3];
    for (int j = 0; j < 4; ++j)
    {
        printf("%.2lf%%\n", (double)results[j] * 100 / sum);
    } 
    return 0;
}