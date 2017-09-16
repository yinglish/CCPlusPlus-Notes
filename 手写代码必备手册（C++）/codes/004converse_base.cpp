#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;


void converse_base(int n, const int d)
{
    stack<int> s;
    int e;

    while (n)
    {
        e = n % d;
        s.push(e);
        n = n / d;
    }

    while (!s.empty())
    {
        e = s.top();
        s.pop();
        printf("%X", e);
    }
}

const int MAXN = 64;

int mystack[MAXN];
int top = -1;

void converse_base2(int n, const int d)
{
    while (n)
    {
        mystack[++top] = n % d;
        n = n / d;
    }

    while (top > -1)
    {
        printf("%X", mystack[top--]);
    }
}

int restore(const char s[MAXN], const int d)
{
    int result = 0;
    int one;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            one = s[i] - '0';
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            one = s[i] - 'A' + 10;
        }
        else
        {
            one = s[i] - 'a' + 10;
        }

        result = result * d + one;
    }

    return result;
}
int main()
{
    printf("test converse_base: \n");
    int a = 7809;
    converse_base(a, 16);
    printf("\n");
    printf("test over!\n");
    printf("test converse_base2: \n");
    int b = 7809;
    converse_base2(b, 16);
    printf("\n");
    printf("test over!\n");

    printf("test restore: \n");
    char str[] = "1e81";
    printf("%d", restore(str, 16));
    printf("\n");
    printf("test over!\n");

    return 0;
}