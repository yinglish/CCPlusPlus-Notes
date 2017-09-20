#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


unsigned int gcd(unsigned int a, unsigned int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

unsigned int gcd1(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        unsigned int tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

unsigned int gcd2(unsigned int a, unsigned int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    unsigned int a, b;
    scanf("%u %u", &a, &b);
    printf("lcd: %u\n", gcd(a, b));
    printf("lcm: %u\n", lcm(a, b));
    return 0;
}