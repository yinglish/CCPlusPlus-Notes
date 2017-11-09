#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

double exp()
{
    char str[20];
    cin >> str;
    switch (str[0])
    {
        case '+': return exp() + exp();
        case '-': return exp() - exp();
        case '*': return exp() * exp();
        case '/': return exp() / exp();
        default: return atof(str);
        //break;
    }
}

int main()
{
    printf("%lf\n", exp());
    return 0;
}