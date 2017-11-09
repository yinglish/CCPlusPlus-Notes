#include <iostream>
#include <cstdio>

using namespace std;

int factor_value();
int term_value();
int expression_value();

int main()
{
    printf("%d\n", expression_value());
    return 0;
}

int expression_value()
{
    //printf("e in\n");
    int value = term_value();
    bool more = true;
    while (more)
    {
        char c = cin.peek();
        if (c == '+' || c == '-')
        {
            cin.get();
            if (c == '+')
                value += term_value();
            else 
                value -= term_value();
        }
        else
            more = false;
    }
    //printf("e out\n");
    return value;
}

int term_value()
{
    //printf("t in\n");
    int result = factor_value();
    bool unfinished = true;
    while (unfinished)
    {
        char c = cin.peek();
        if (c == '*' || c == '/')
        {
            cin.get();
            if (c == '*') result *= factor_value();
            else result /= factor_value();
        }
        else unfinished = false;
    }
    //printf("t out\n");
    return result;
}

int factor_value()
{
    //printf("f in\n");
    int result = 0;
    char c = cin.peek();
    if (c == '(')
    {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else 
        while(isdigit(c))
        {
            result = result * 10 + c - '0';
            cin.get();
            c = cin.peek();
        }
    //printf("f out\n");
    return result;
}