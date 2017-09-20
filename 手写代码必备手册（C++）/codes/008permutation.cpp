#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

static void print_permutation_r(int n, int cur, int p[])
{
    int i, j;
    if (cur == n)
    {
        for (i = 0; i < n; ++i)
        {
            printf("%d ", p[i]);
        }
        printf("\n");
    }

    for (i = 1; i <= n; ++i)
    {
        int used = 0;
        for (j = 0; j < cur; ++j)
        {
            if (p[j] == i)
            {
                used = 1;
            }
        }

        if (!used)
        {
            p[cur] = i;
            print_permutation_r(n, cur + 1, p);
        }
    }
}

void print_permutation(int n)
{
    int *p = (int *)malloc(sizeof(int) * n);
    print_permutation_r(n, 0, p);
    free(p);
    return;
}

int main()
{
    print_permutation(3);
    print_permutation(4);
    return 0;
}