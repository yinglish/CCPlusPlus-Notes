#include <cstdio>

int main()
{
    double d;
    scanf("%lf", &d); // 必须为lf, 不能是f
    printf("%.12lf", d); 
    return 0;
}