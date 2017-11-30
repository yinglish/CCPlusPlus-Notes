#include <iostream>

using namespace std;

int a[30]; 
int N;

int ways(int w, int k)
{
    if (w == 0)
    {
        return 1;
    }

    if (k <= 0)
    {
        return 0;
    }

    return ways(w, k - 1) + ways(w - a[k], k - 1);
}


int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
    }
    cout << ways(40, N) << endl;
    return 0;
}