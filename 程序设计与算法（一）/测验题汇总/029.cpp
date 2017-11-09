#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int numbers[11] ={0};
    int value;
    int i = 0;
    int count = 0;
    while (cin >> value)
    {
        numbers[i] = value;
        i++;
    }
    for (i = 0; i < 10; ++i)
    {
        if (numbers[i] <= numbers[10] + 30)
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}