#include "fibonacci.h"


// fill the array v with values fro, the fibonacci series
void get_fibo_series(int *v, int size)
{       
    *v = 0;
    *(v+1) = 1;
    for(int i=2;i<size;++i)
    {
        *(v+i) = *(v+i-2)+*(v+i-1);
    }
}