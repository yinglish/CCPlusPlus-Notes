#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

void print_permutation(char s[], int n)
{
    sort(&s[0], &s[n]);
    do 
    {
        for (int i = 0; i < n; ++i)
        {
            printf("%c", s[i]);
        }
        printf("\n");
    } while (next_permutation(&s[0], &s[n]));
    return;
}

int main()
{
    char s[] = "ABC";
    char s1[] = "AAA";
    print_permutation(s, 3);
    print_permutation(s1, 3);
    return 0;
}