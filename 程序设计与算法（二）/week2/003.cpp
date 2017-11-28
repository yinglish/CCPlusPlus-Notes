#include <iostream>
#include <cmath>

using namespace std;

int N;
int queenPos[100];

void nQueen(int k)
{
    if (k == N)
    {
        for (int i = 0; i < N; ++i)
        {
            cout << queenPos[i] + 1 << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        int j = 0;
        for (; j < k; ++j)
        {
            if (i == queenPos[j] || abs(i - queenPos[j]) == abs(k - j))
            {
                break;
            }
        }

        if (j == k)
        {
            queenPos[k] = i;
            nQueen(k + 1);
        }
    }
}

int main()
{
    cin >> N;
    nQueen(0);

    return 0;
}