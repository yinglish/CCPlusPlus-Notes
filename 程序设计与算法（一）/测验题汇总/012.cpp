#include <cstdio>

int main()
{
    int number;
    scanf("%d", &number);
    printf("%s\n", (number % 2) ? "odd" : "even");
    return 0;
}