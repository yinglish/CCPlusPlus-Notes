#include <stdio.h>
#include <stdlib.h>

int myCompare(const void * elem1, const void *elem2)
{
    unsigned int *p1, *p2;
    p1 = (unsigned int *)elem1;
    p2 = (unsigned int *)elem2;

    return (*p1) % 10 - (*p2) % 10;
}

int main(void)
{
    unsigned int arr[5] = {10, 123, 11, 9, 27};
    qsort(arr, 5, sizeof(unsigned int), myCompare);
    for (int i = 0; i < 5; ++i)
    {
        printf("%u ", arr[i]);
    }
    printf("\n");
    return 0;
}