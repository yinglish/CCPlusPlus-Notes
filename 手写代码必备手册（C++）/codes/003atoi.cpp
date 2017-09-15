#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int atoi(const char *str)
{
    int num = 0;
    const int len = strlen(str);
    int sign = 1;

    int i = 0;
    // skip spaces first
    while (str[i] == ' ' && i < len) // why less than len instead of less or equal to len
    {
        i++;
    }

    //cout << "i : " << i << endl;
    if (str[i] == '+')
    {
        i++;
    }
    else if (str[i] == '-')
    {
        i++;
        sign = -1;
    }

    for (; i < len; ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            break;
        }

        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] > INT_MAX % 10))
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        num = 10 * num + str[i] - '0';
    }

    return num * sign;
}



int main()
{

    cout << "-3924x8fc: " << atoi("-3924x8fc") << endl;
    cout << " + 413: " << atoi(" + 413") << endl;
    cout << "++c: " << atoi("++c") << endl;
    cout << "++1: " << atoi("++1") << endl;
    cout << "2147483648: " << atoi("2147483648") << endl;
    cout << "123: " << atoi("123") << endl;
    cout << " : " << atoi(" ") << endl;
    return 0;
}