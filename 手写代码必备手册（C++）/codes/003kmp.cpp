#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

void compute_prefix(const char *pattern, int next[])
{
    int i;
    int j = -1;
    const int m = strlen(pattern);

    next[0] = j;
    for (i = 1; i < m; i++)
    {
        if (j > -1 && pattern[j + 1] != pattern[i]) j = -1;

        if (pattern[i] == pattern[j + 1]) j++;
        next[i] = j;
    }
}

int kmp(const char *text, const char *pattern)
{
    int i;
    int j = -1;
    const int n = strlen(text);
    const int m = strlen(pattern);
    if (n == 0 && m == 0) return 0;
    if (m == 0) return 0;
    int *next = (int *)malloc(sizeof(int) * m);

    compute_prefix(pattern, next);

    for (i = 0; i < m; ++i)
    {
        cout << next[i] << " ";
    }
    cout << endl;

    for (i = 0; i < n; ++i)
    {
        while (j > -1 && pattern[j + 1] != text[i]) j = next[j];

        if (text[i] == pattern[j + 1]) j++;
        if (j == m - 1)
        {
            free(next);
            return i - j;
        }
    }

    free(next);
    return -1;
}

int main()
{
    char text[] = "ABC ABCDAB ABCDABCDABDE";
    char pattern[] = "ABCDABD";
    char *ch = text;
    int i = kmp(text, pattern);

    if (i >= 0) printf("matched @: %s\n", ch + i);
    return 0;
}