#include "functions.h"

// Filling the array with a Fibonacci series, and printing the values
int generate_series(int *v, int size)
{
    *v = 0;
    printf("%d \n", *(v));
    *(v+1) = 1;
    printf("%d \n", *(v+1));

    for(int i=2;i<size;++i)
    {
        *(v+i) = *(v+i-2)+*(v+i-1);
        printf("%d \n", *(v+i));
    }
    return 0;
 }
