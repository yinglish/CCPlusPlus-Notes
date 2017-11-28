#include <iostream>

using namespace std;

int stairs(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return stairs(n -1) + stairs(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << stairs(n) << endl;
    return 0;
}