#include <iostream>
#include <cstdio>

int main()
{
    bool found = false;
    int arr[5][5];
    int i, j;
    int rowMax, rowMaxColumn;
    for (i = 0; i < 5; ++i)
    {
        for (j = 0; j < 5; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < 5; ++i)
    {
        rowMax = arr[i][0];
        rowMaxColumn = 0;
        for (j = 1; j < 5; ++j)
        {
            if (arr[i][j] > rowMax)
            {
                rowMax = arr[i][j];
                rowMaxColumn = j;
            }
        }
        for (j = 0; j < 5; ++j)
        {
            if (arr[j][rowMaxColumn] < rowMax)
            {
                break;
            }
        }
        if (j == 5)
        {
            found = true;
            printf("%d %d %d\n", i + 1, rowMaxColumn + 1, rowMax);
        }
    }
    if (!found)
        printf("not found\n");

    return 0;
}