// INCLUDE HEADER FILES NEEDED BY YOUR edgesROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scoreCore(int numNodes, int rootNode, int* values, int** edges, int *checked, int *highestScore, int *curScore)
{
    int i, j;
    //int isLeaf = 0;
    
    //if (checked[rootNode - 1])
    //{
        //checked[rootNode - 1] = 0;
        //return;
    //}
    
    *curScore *= values[rootNode - 1];
    checked[rootNode - 1] = 1;
    for (j = 0; j < numNodes - 1; ++j)
    {
        if (*(*(edges + j)) == rootNode && !checked[*(*(edges + j) + 1) - 1])
        {
            //edgesrintf("%d\n", checked[*(*(edges + 2 * j) + 1) - 1]);
            break;
        }         
    }

    if (j == (numNodes - 1))
    {
        if (*highestScore < *curScore)
        {
            *highestScore = *curScore;
            *curScore /= values[rootNode - 1];
        }
        checked[rootNode - 1] = 0;
        return;
    }
    else
    {
        for (i = 0; i < (numNodes - 1); ++i)
        {
            if (*(*(edges + i)) == rootNode && !checked[*(*(edges + i) + 1) - 1])
            {
                scoreCore(numNodes, *(*(edges + i) + 1), values, edges, checked, highestScore, curScore);
            }
        }
        checked[rootNode - 1] = 0;
        return;
    }
}

int calculateMaxScore(int numNodes, int rootNode, int* values, int** edges)
{
    // WRITE YOUR CODE HERE
    //int i, j, k;
    //int numberOfEdge = sizeof(edges) / sizeof(int) / 2;
    int highestScore = -10000, curScore = 1;
    
    int *checked = (int *)malloc(sizeof(int) * numNodes);
    memset(checked, 0, numNodes); 

    scoreCore(numNodes, rootNode, values, edges, checked, &highestScore, &curScore);

    free(checked);
    return highestScore;
}
// FUNCTION SIGNATURE ENDS


int main()
{
    int numNodes = 5;
    int rootNode = 1;
    int values[] = {2, 4, 10, 20, 1};
    int **edges = (int **)malloc(sizeof(int *) * 4);
    for (int i = 0; i < 4; ++i)
    {
         *(edges + i) = (int *)malloc(sizeof(int) * 2);
    }
    *(*edges + 0) = 1;
    *(*edges + 1) = 2;
    *(*(edges + 1) + 0) = 1;
    *(*(edges + 1) + 1) = 3;
    *(*(edges + 2) + 0) = 2;
    *(*(edges + 2) + 1) = 4;
    *(*(edges + 3) + 0) = 2;
    *(*(edges + 3) + 1) = 5;

    printf("%d\n", calculateMaxScore(numNodes, rootNode, values, edges));
    return 0;
}