#include <iostream>
#include <cstdio>

using namespace std;

void hanoi(int n, char src, char mid, char dest)
{
    if (n == 1)
    {
        printf("%d from %c to %c\n", n, src, dest);
        return;
    }
    else
    {
        hanoi(n - 1, src, dest, mid);
        printf("%d from %c to %c\n", n, src, dest);
        hanoi(n - 1, mid, src, dest);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    hanoi(3, 'A', 'B', 'C');
    return 0;
}