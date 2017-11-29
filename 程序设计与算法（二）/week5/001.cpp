#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 101;
int D[MAX][MAX];
int max_sum[MAX][MAX];

int n;

int maxSum(int i, int j)
{
    if (i == n)
    {
        return D[i][j];
    }
    if (max_sum[i][j] != -1)
    {
        return max_sum[i][j];
    }

    max_sum[i][j] = max(maxSum(i + 1, j), maxSum(i + 1, j + 1)) + D[i][j];
    return max_sum[i][j];
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <=i; ++j)
        {
            cin >> D[i][j];
            max_sum[i][j] = -1;
        }
    }
    cout << maxSum(0, 0) << endl;
    return 0;
}