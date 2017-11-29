#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 101;
int D[MAX][MAX];
int max_sum[MAX][MAX];

int n;


int main()
{
    cin >> n;
    // 数组并不是从0的下标开始使用的
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> D[i][j];
            //max_sum[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        max_sum[n][i] = D[n][i];
    }

    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = 1; j <= i; ++j)
        {
            max_sum[i][j] = max(max_sum[i + 1][j], max_sum[i + 1][j + 1]) + D[i][j];
        }
    }
    cout << max_sum[1][1] << endl;
    return 0;
}