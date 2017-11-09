#include <cstdio>

#define WATER 20
#define PI 3.14

int main()
{
    int h, r;
    scanf("%d %d", &h, &r);
    printf("%d\n", (int)((double)(1000 * 20) / (PI * r * r * h) + 1));
    return 0;
}