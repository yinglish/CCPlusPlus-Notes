#include <iostream>

using namespace std;

void hanoi(int n, char src, char mid, char dest)
{
    if (n == 0)
    {
        return;
    }

    hanoi(n - 1, src, dest, mid);
    cout << src << " -> " << dest << endl;
    hanoi(n - 1, mid, src, dest);
}


int main()
{
    hanoi(3, 'A', 'B', 'C');
    return 0;
}