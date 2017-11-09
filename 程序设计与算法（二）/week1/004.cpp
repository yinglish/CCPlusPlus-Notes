#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

int GetBit(char c, int i)
{
    return (c >> i) & 1;
}

void SetBit(char & c, int i, int v)
{
    if (v)
    {
        c |= (1 << i);
    }
    else
    {
        c &= ~(1 << i);
    }
}

void FlipBit(char & c, int i)
{
    c ^= (1 << i);
}

void OutputResult(int t, char result[])
{
    cout << "PUZZLE #" << t << endl;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cout << GetBit(result[i], j);
            cout << " ";
        }
        cout << endl;
    }     
}

int main()
{
    char oriLights[5];
    char lights[5];
    char result[5];
    char switchs;
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        memset(oriLights, 0, sizeof(oriLights));
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 6; ++j)
            {
                int s;
                cin >> s;
                SetBit(oriLights[i], j, s);
            }
        
        for (int i = 0; i <= 63; ++i)
        {
            memcpy(lights, oriLights, 5);
            for (int j = 0; j < 5; ++j)
            {
                result[j] = switchs;
                for (int k = 0; k < 6; ++k)
                {
                    if (GetBit(result[j], k))
                    {
                        if (k > 0)
                            FlipBit(lights[j], k - 1);
                        FlipBit(lights[j], k);
                        if (k < 5)
                            FlipBit(lights[j], k + 1);
                    }
                }
                if (j < 4)
                    lights[j + 1] ^= switchs;
                switchs = lights[j];
            }
            if (lights[4] == 0)
            {
                OutputResult(t, result);
                break;
            }   
        }
    }
    return 0;
}