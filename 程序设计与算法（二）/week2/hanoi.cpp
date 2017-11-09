#include <iostream>

using namespace std;

void Hanoi(int n, char src, char mid, char des)
{
    if (n == 0)
        return;
    if (n == 1)
        cout << src << "->" << des << endl;
    else
    {
        Hanoi(n - 1, src, des, mid);
        cout << src << "->" << des << endl;
        Hanoi(n - 1, mid, src, des);
    } 
}

int main()
{
    int n;
    cin >> n;
    Hanoi(n, 'A', 'B', 'C');

    return 0;
}