#include <iostream>
#include <cstdio>
#include <cstdlib>

long long pellNum(int k)
{
    long long a = 1, b = 2, c;
    if (k == 1 || k == 2)
        return k;
    if (k > 2)
    {
        for (int i = 3; i <= k; ++i)
        {
            //c = (b * 2) % 32767 + a % 32767;
            //a = b % 32767;
            //b = c;
            c = (1 >> 15| (b * 2)) + (0 | a >> 15);
            a = (0 | b >> 15);
            b = c;
        }
        //return b % 32767; 
        return (0 | b >> 15);       
    }
    return -1;
}

int main()
{
    int num, value;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i)
    {
        scanf("%d", &value);
        printf("%lld\n", pellNum(value));
    }
    return 0;
}