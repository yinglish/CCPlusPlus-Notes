#include <cstdio>
#include <cmath>

int main()
{
    float a, b, c;
    float delta;
    float rNumber, iNumber;
    scanf("%f %f %f", &a, &b, &c);
    delta = b * b - 4 * a * c;
    if (fabs(delta) < 1e-6)
    {
        printf("x1=x2=%.5f", fabs(-b / (2 * a)) < 1e-6 ? 0 : -b / (2 * a));
    }
    else if (delta > 0)
    {
        printf("x1=%.5f;", (fabs((-b + sqrt(b*b-4*a*c)) /(2*a)) < 1e-6) ? 0 :  (-b + sqrt(b*b-4*a*c)) /(2*a));
        printf("x2=%.5f", (fabs((-b - sqrt(b*b-4*a*c)) /(2*a)) < 1e-6) ? 0 :  (-b - sqrt(b*b-4*a*c)) /(2*a));
    }
    else
    {
        delta = fabs(delta);
        rNumber = -b / (2 * a);
        if (fabs(rNumber) < 1e-6)
            rNumber = fabs(rNumber);
        iNumber = sqrt(delta) / (2 * a);
        printf("x1=%.5f+%.5f" "i;", rNumber, iNumber);
        printf("x2=%.5f-%.5fi", rNumber, iNumber);
    }
    return 0;

}