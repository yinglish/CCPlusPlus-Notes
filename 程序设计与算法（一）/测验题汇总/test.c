// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
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
    printf("test4\n");
    printf("%x\n", edges);
    printf("%x\n", edges + 1);
    for (j = 0; j < numNodes - 1; ++j)
    {
        printf("test7\n");
        *(*(edges + j));
        printf("test9\n");
        checked[*(*(edges + j) + 1) - 1];
        printf("%x\n", edges);
        printf("%x\n", edges + 1);
        printf("%d\n", *(*edges));
        printf("%d\n", *((edges + j) + 1) - 1);
        printf("test11\n");
        printf("%d\n", (int)checked[*(*(edges + 2 * j) + 1) - 1]);
        printf("test10\n");
        if (*(*(edges + 2 * j)) == rootNode && !checked[*(*(edges + 2 * j) + 1) - 1])
        {
            //printf("%d\n", checked[*(*(edges + 2 * j) + 1) - 1]);
            printf("test6\n");
            break;
        }
        printf("test8\n");
            
    }
    
    printf("test5\n");
    if (j == (numNodes - 1))
    {
        if (*highestScore < *curScore)
        {
            *highestScore = *curScore;
            printf("%d\n", *highestScore);
            *curScore /= values[rootNode];
        }
        checked[rootNode - 1] = 0;
        return;
    }
    else
    {
        for (i = 0; i < (numNodes - 1); ++i)
        {
            if (*(*(edges + 2 * j)) == rootNode && !checked[*(*(edges + 2 * j) + 1) - 1])
            {
                scoreCore(numNodes, *(*(edges + 2 * j) + 1), values, edges, checked, highestScore, curScore);
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
    int a = 5;
    int *p = &a;
    int **pp = &p;
    printf("%d\n", **pp);
    printf("test1\n");
    printf("%x\n", pp);
    printf("%x\n", pp + 1);
    memset(checked, 0, numNodes);
    printf("test2\n");
    
    scoreCore(numNodes, rootNode, values, edges, checked, &highestScore, &curScore);
    printf("test3\n");

    free(checked);
    return highestScore;
}
// FUNCTION SIGNATURE ENDS


int main()
{
    int numNodes = 5;
    int rootNode = 1;
    int values[] = {2, 4, 10, 20, 1};
    int edges[][2] = {{1, 2}, {1, 3}, {2, 4}, {2, 5}}; 
    printf("%x\n", edges); 
    printf("%x\n", &edges[0][0]);
    printf("%x\n", &edges[0][1]);
    printf("%x\n", &edges[1][0]);
    printf("%d\n", calculateMaxScore(numNodes, rootNode, values, (int **)edges));
    return 0;
}