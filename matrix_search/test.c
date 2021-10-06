/*
 * Copyright (C) 2020 University of Bologna
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 *
 * Authors: Manuele Rusci, UniBO (manuele.rusci@unibo.it)
 *          Leonardo Ravaglia, UniBO (leonardo.ravaglia2@unibo.it)
 */
#include "pmsis.h"
#include "fibonacci.h"

// defines
#define N 10
#define M 6

// structure definition
struct coordinates {
    int ROW, COLUMN;
};
typedef struct coordinates coordinates_t;

// variable declaration
static int a[N*M];

// matrix search function
coordinates_t matrix_search(int *a, int element, int N_size, int M_size){

    // found=1 if the element is found in the matrix, otherwise found=0
    int found = 0;
    coordinates_t s;

    /*****************
     * Put here the 
     * missing code
    *****************/

    if (found==0) {
        printf(">> el NOT FOUND!\n");
        s.ROW = -1;
        s.COLUMN = -1;
    }

    return s;
}


int main()
{
    // Filling the matrix with the values of a Fibonacci series
    get_fibo_series(a, M*N);

    // Suppose we want to find whether an element (el) is present in a matrix or not:
    int el = 610;
    // expected coordinated of el=610 if M=6 and N=10
    int r_gold = 2;
    int c_gold =3;

    coordinates_t coord; // coordinates of the searched element. (-1,-1) means not found
    coord.ROW = -1;
    coord.COLUMN = -1;

    // search value el into matrix a
    coord = matrix_search(a, el, N, M);

    // check result
    if (coord.ROW ==-1) {
        printf("Element NOT found!\n");
    } else {
        printf("Found coordinates -> ROW: %d  COLUMN: %d\n", coord.ROW, coord.COLUMN);
        if ((coord.ROW == r_gold) && (coord.COLUMN == r_gold))
            printf("Test OK!\n");
        else
            printf("Test NOT OK\n");
    } 



}
