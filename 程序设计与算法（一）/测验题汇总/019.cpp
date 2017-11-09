#include <cstdio>

int main()
{
    int numbers, i, gold, silver, copper, sum;
    int sumOfGold = 0, sumOfSilver = 0, sumOfCopper = 0; 
    scanf("%d", &numbers);
    for (i = 0; i < numbers; ++i)
    {
        scanf("%d %d %d", &gold, &silver, &copper);
        sumOfGold += gold;
        sumOfSilver += silver;
        sumOfCopper += copper;
    }
    sum = sumOfCopper + sumOfGold + sumOfSilver;
    printf("%d %d %d %d\n", sumOfGold, sumOfSilver, sumOfCopper, sum);
    return 0;
}