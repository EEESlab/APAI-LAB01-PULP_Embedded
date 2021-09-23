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
    int n,key;

    // set the side length of the matrix
    int side = 5;

    // C matrices are 1-dimensional
    int square_size = side*side;  // = 25
    int a[square_size];
    // intialize the array with 0s
    for (int i=0; i<square_size; i++) a[i]=0;

    // use the generate_series() function to fill the matrix with Fibonacci series
    generate_series(a, square_size);

    // We can either scan the elements with 1 index, as before
    // or we can scan the matrix using 2 indeces (i and j).
    // Suppose we want to find whether an element (el) is present in a matrix or not, e.g. el=144:
    int el = 46368;

    for (int i=0; i<side; i++){
        for (int j=0; j<side; j++){
            if (a[i*5+j]==el) {printf("el=144 >> FOUND\n");}
        }
    }

}
