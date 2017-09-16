#include <stdio.h>
#include <stdlib.h>

typedef int heap_elem_t;

typedef struct heap_t 
{
    int size;
    int capacity;
    heap_elem_t *elems;
    int (*cmp)(const heap_elem_t*, const heap_elem_t*);
} heap_t;

int cmp_int(const int *x, const int *y)
{
    const int sum = *x - *y;
    if (sub > 0)
    {
        return 1;
    }
    else if (sub < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}



int main()
{
    return 0;
}