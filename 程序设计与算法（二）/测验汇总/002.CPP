#include <iostream>
#include <cstdio>

int originals[3][3];
int copies[3][3];


void applyMethod(int i)
{
    swtich (i)
    {
        case 1:
        copies[0][0] = (copies[0][0] + 1) % 3;
        copies[0][1] = (copies[0][1] + 1) % 3;
        copies[1][0] = (copies[1][0] + 1) % 3;
        copies[1][1] = (copies[1][1] + 1) % 3;
        break;
        case 2:
        copies[0][0] = (copies[0][0] + 1) % 3;
        copies[0][1] = (copies[0][1] + 1) % 3;
        copies[0][2] = (copies[0][2] + 1) % 3;
        break;
        case 3:
        copies[0][1] = (copies[0][1] + 1) % 3;
        copies[0][2] = (copies[0][2] + 1) % 3;
        copies[1][1] = (copies[1][1] + 1) % 3;
        copies[1][2] = (copies[1][2] + 1) % 3;
        break;
        case 4:
        copies[0][0] = (copies[0][0] + 1) % 3;
        copies[1][0] = (copies[1][0] + 1) % 3;
        copies[2][0] = (copies[2][0] + 1) % 3;
        break;
        case 5:
        copies[0][1] = (copies[0][1] + 1) % 3;
        copies[1][0] = (copies[1][0] + 1) % 3;
        copies[1][2] = (copies[1][2] + 1) % 3;
        copies[1][3] = (copies[1][3] + 1) % 3;
        copies[2][1] = (copies[2][1] + 1) % 3;
        break;
        case 6:
        copies[2][0] = (copies[2][0] + 1) % 3;
        copies[2][1] = (copies[2][1] + 1) % 3;
        copies[2][2] = (copies[2][2] + 1) % 3;
        break;
        case 7:
        copies[1][0] = (copies[1][0] + 1) % 3;
        copies[1][1] = (copies[1][1] + 1) % 3;
        copies[2][0] = (copies[2][0] + 1) % 3;
        copies[2][1] = (copies[2][1] + 1) % 3;
        break;
        case 8:
        copies[2][0] = (copies[2][0] + 1) % 3;
        copies[2][1] = (copies[2][1] + 1) % 3;
        copies[2][2] = (copies[2][2] + 1) % 3;
        break;
        case 9:
        copies[1][1] = (copies[1][1] + 1) % 3;
        copies[1][2] = (copies[1][2] + 1) % 3;
        copies[2][1] = (copies[2][1] + 1) % 3;
        copies[2][2] = (copies[2][2] + 1) % 3;
        break;
        default:
        break;
    }
}

bool checkAllZero()
{
    bool result = true;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (copies[i][j] != 0)
            {
                result = false;
                break;
            }
        }
        if (!result)
        {
            break;
        }
    }
    return result;
}

void applyAllMethods(int method[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        while (method[i] != 0)
        {
            applyMethod(method[i] + 1);
            method[i]--;
        }
    }
}

void printResult(int method[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        while (method[i] != 0)
        {
            cout << i + 1 << " ";
            method[i]--;
        }
    }
}

int main()
{
    int method[9] = {0};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> originals[i][j];
            copies[i][j] = originals[i][j];
        }
    }

    for (int k = 0; k < 9; ++k)
    {
        for (int i = 1; i <= 3; ++i)
        {
            method[k] = i;
            applyAllMethods(method, 9);
            if (checkAllZero)
            {
                printResult(method, 9);
            }
        }
    }

    return 0;
}