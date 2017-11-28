#include <iostream>

using namespace std;

int expression_value();
int term_value();
int factor_value();

int main()
{
    cout << expression_value() << endl;
    return 0;
}

int expression_value()
{
    int result = term_value();
    bool more = true;
    while (more) 
    {
        char op = cin.peek();
        if (op == '+')
        {
            cin.get();
            result += term_value();
        }
        else if (op == '-')
        {
            cin.get();
            result -= term_value();
        }
        else
        {
            more = false;
        }
    }

    return result;
}

int term_value()
{
    int result = factor_value();
    bool more = true;
    while (more) 
    {
        char op = cin.peek();
        if (op == '*')
        {
            cin.get();
            result *= factor_value();
        }
        else if (op == '/')
        {
            cin.get();
            result /= factor_value();
        }
        else
        {
            more = false;
        }
    }

    return result;
}

int factor_value()
{
    int result = 0;
    char op = cin.peek();
    if (op == '(')
    {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else
    {
        char c;// = cin.get();
        while (cin.get(c)) // 想在键盘输入EOF是不可能的！！！
        {
            //cin.get();
            result = 10 * result + op - '0';
            //op = cin.peek();
            //c = cin.get();
        }
    }
    return result;
}