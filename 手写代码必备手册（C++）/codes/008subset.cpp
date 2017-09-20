#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void print_subset1(int *s, int n, int *p, int cur, int ed)
{
    int i, j;
    for (i = ed;  i < n; i++)
    {
        // 选择s[i]
        p[cur] = s[i];
        for (j = 0; j <= cur; j++) printf("%d ", p[j]);
        printf("\n");
        // 不选s[i]
        print_subset1(s, n, p, cur + 1, i + 1);
    }
}

// 位向量法

void print_subset2(int *s, int n, char *b, int cur)
{
    int i;
    if (cur == n)
    {
        for (i = 0; i < n; ++i)
        {
            if (b[i])
            {
                printf("%d ", s[i]);
            }
        }
        printf("\n");
        return;
    }
    //printf("test\n");

    b[cur] = 1;
    print_subset2(s, n, b, cur + 1);
    b[cur] = 0;
    print_subset2(s, n, b, cur + 1);
}

// 二进制法

void print_subset3(int *s, int n)
{
    int i, j;
    for (i = 1; i < (1 << n); ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                printf("%d ", s[j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, i;

    while (scanf("%d", &n) > 0)
    {
        int *s = (int *)malloc(n * sizeof(int));
        int *p = (int *)malloc(n * sizeof(int));
        char *b = (char *)malloc(n * sizeof(char));

        for (i = 0; i < n; ++i) scanf("%d", &s[i]);

        print_subset1(s, n, p, 0, 0); putchar('\n');
        print_subset2(s, n, b, 0); putchar('\n');
        print_subset3(s, n);

        free(s);
        free(p);
        free(b);
    }
    return 0;
}