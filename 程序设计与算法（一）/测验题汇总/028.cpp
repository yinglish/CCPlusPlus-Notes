#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int numbers, value, sum = 0;
    cin >> numbers;
    int *arr = new int[numbers + 1];
    int i = 0;
    while (cin >> value)
    {
        arr[i] = value;
        ++i;
    }

    for (int j = 0; j < numbers; ++j)
    {
        if (arr[j] == arr[numbers])
            ++sum;
    }
    cout << sum << endl;

    return 0;
}