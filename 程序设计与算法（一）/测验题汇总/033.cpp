#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

int main()
{
    int n, m;
    int **picture;
    scanf("%d %d", &n, &m);
    picture = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i)
    {
        *(picture + i) = (int *)malloc(sizeof(int) * m);
    }
    
    for (int i = 0; i < n; ++i)
    {
        
        for (int j = 0; j < m; ++j)
        {
            
            scanf("%d", *(picture + i) + j);
            
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i > 0 && i < n - 1 && j > 0 && j < m - 1)
                printf("%d ", (int)round((double)(*(*(picture + i) + j) + *(*(picture + i - 1) + j) + *(*(picture + i + 1) + j) 
                                    + *(*(picture + i) + j + 1) + *(*(picture + i) + j - 1)) / 5));
            else
                printf("%d ", *(*(picture + i) + j));
        }
        printf("\n");
    }

    return 0;
}