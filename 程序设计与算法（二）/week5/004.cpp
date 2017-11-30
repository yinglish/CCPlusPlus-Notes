#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 100;

char str1[MAX];
char str2[MAX];

int maxLen[MAX][MAX];


int main()
{
    while (cin >> str1 >> str2)
    {
        int len1 = strlen(str1);
        int len2 = strlen(str2);

        for (int i = 0; i <= len1; ++i)
        {
            maxLen[i][0] = 0;
        }
        for (int j = 0; j <= len2; ++j)
        {
            maxLen[0][j] = 0;
        }

        for (int i = 1; i <= len1; ++i)
        {
            for (int j = 1; j <= len2; ++j)
            {
                if (str1[i - 1] == str2[j - 1])  // 注意此处的下标
                {
                    maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
                }
                else
                {
                    maxLen[i][j] = max(maxLen[i - 1][j], maxLen[i][j - 1]);
                }
            }
        }

        cout << maxLen[len1][len2] << endl;
    } 
    return 0;
}