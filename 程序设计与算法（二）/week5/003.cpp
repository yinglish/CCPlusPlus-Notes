#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 20;

int a[MAX];

int maxLen[MAX];

void findMaxLen(int n)
{
    for (int i = 0; i < n; ++i)
    {
        maxLen[i] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        int maxCurrent = maxLen[i];
        for (int j = 0; j < i; ++j)
        {
            //int maxTmp = maxLen[j];
            if (a[j] < a[i])
            {
                int maxTmp = maxLen[j] + 1;

                if (maxTmp > maxCurrent)
                {
                    maxCurrent = maxTmp;
                }
            } 
        }
        maxLen[i] = maxCurrent;
    }
}



int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    findMaxLen(n);
    cout << *max_element(maxLen, maxLen + n) << endl;
    return 0;
}