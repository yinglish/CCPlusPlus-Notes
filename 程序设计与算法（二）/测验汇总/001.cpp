#include <iostream>

using namespace std;


int GetBit(int v, int i)
{
    return v &= (1 << i);
}

void FlipBit(int &v, int i)
{
    v ^= (1 << i);
}


int main()
{
    char s[30];
    int in = 0, out = 0, val = 0;
    int i;
    int count1 = 0;
    int count2 = 0;
    int inputSize = 0;
    bool succeed0 = true;
    bool succeed1 = true;
    cin >> s;
    //cout << s << endl;
    i = 0;
    // 将第一行转化为int类型的数值
    while (s[i] != '\0')
    {
        in = 2 * in + (s[i] - '0');
        ++inputSize;
        i++;
    }
    cin >> s;
    //cout << s << endl;
    i = 0;
    // 将第二行转化为int类型的数值
    while (s[i] != '\0')
    {
        out = 2 * out + (s[i] - '0');
        i++;
    }

    //cout << in << ", " << out << endl;
    val = in;
    // 最低位不按下
    for (i = 1; i < inputSize; ++i)
    {
        if (GetBit(val, i - 1) != GetBit(out, i - 1))
        {
            ++count1;
            FlipBit(val, i - 1);
            FlipBit(val, i);
            if (i < inputSize - 1)
            {
                FlipBit(val, i + 1);
            }
        }
    }
    if (GetBit(val, inputSize - 1) != GetBit(out, inputSize - 1))
    {
        succeed0 = false;
    }

    val = in;
    // 最低位按下
    count2++;
    FlipBit(val, 0);
    FlipBit(val, 1);
    for (i = 1; i < inputSize; ++i)
    {
        if (GetBit(val, i - 1) != GetBit(out, i - 1))
        {
            ++count2;
            FlipBit(val, i - 1);
            FlipBit(val, i);
            if (i < inputSize - 1)
            {
                FlipBit(val, i + 1);
            }
        }
    }
    if (GetBit(val, inputSize - 1) != GetBit(out, inputSize - 1))
    {
        succeed1 = false;
    }

    if (!succeed0 && !succeed1)
    {
        cout << "impossible" << endl;
    }
    else if (succeed0 && !succeed1)
    {
        cout << count1 << endl;
    }
    else if (!succeed0 && succeed1)
    {
        cout << count2 << endl;
    }
    else
    {
        if (count1 < count2)
            cout << count1 << endl;
        else
            cout << count2 << endl;
    }

    return 0;
}