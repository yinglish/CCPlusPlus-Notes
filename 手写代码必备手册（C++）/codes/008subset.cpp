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

int main()
{
    int s[] = {1, 2, 3};
    int p[3];
    print_subset1(s, 3, p, 0, 0);
    return 0;
}