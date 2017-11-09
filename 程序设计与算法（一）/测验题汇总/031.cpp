#include <iostream>
#include <cstdio>

int main()
{
    int l, m, low, high, leftNumber = 0;
    scanf("%d %d", &l, &m);
    char *positions = new char[l + 1];
    for (int i = 0; i <= l; ++i)
    {
        positions[i] = 1;
    }
    for (int j = 0; j < m; ++j)
    {
        scanf("%d %d", &low, &high);
        for (int k = low; k <= high; ++k)
        {
            positions[k] = 0;
        }
    }
    for (int p = 0; p <= l; ++p)
    {
        if (positions[p] == 1)
            leftNumber++;
    }
    printf("%d\n", leftNumber);
    return 0;
}