/*
 * Copyright (C) 2020 University of Bologna
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 *
 * Authors: Manuele Rusci, UniBO (manuele.rusci@unibo.it)
 */
#include "pmsis.h"

// Filling the array with a Fibonacci series, and printing the values
int generate_series(int *v, int sq_size)
{

    *v = 0;
    printf("%d \n", *(v));
    *(v+1) = 1;
    printf("%d \n", *(v+1));

    for(int i=2;i<sq_size;++i)
    {
        *(v+i) = *(v+i-2)+*(v+i-1);
        printf("%d \n", *(v+i));
    }

    return 0;
 }


int main()
{

    // set the side length of the matrix
    int N = 5;
    int M = 5;

    // C matrices are 1-dimensional
    int mat_size = N*M;  // = 25
    int a[mat_size];
    // intialize the matrix with 0s
    for (int i=0; i<mat_size; i++) a[i]=0;

    // Use the generate_series() function to fill the matrix with Fibonacci series
    generate_series(a, mat_size);

    // We can either scan the elements with 1 index, as before
    // or we can scan the matrix using 2 indeces (i and j).
    // Suppose we want to find whether an element (el) is present in a matrix or not, e.g. el=144:
    int el = 144;

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (a[i*M+j]==el) {printf("el=144 >> FOUND\n");}
        }
    }

}
