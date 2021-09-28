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
#include "functions.h"

// structure definition
struct coordinates {
    int ROW, COLUMN;
};
typedef struct coordinates Struct;

Struct matrix_search(int *a, int element, int N_size, int M_size){

  // found=1 if the element is found in the matrix, otherwise found=0
  int found = 0;
  Struct s;

  for (int i=0; i<N_size; i++){
      for (int j=0; j<M_size; j++){
          // notice that we move in the matrix with 2 indeces (i, j)
          if (*(a+i*M_size+j)==element){
              printf(">> el=%d FOUND\n", element);
              s.ROW = i;
              s.COLUMN = j;
              found = 1;
          }
      }
  }

  if (found==0) {
      printf(">> el NOT FOUND!\n");
      s.ROW = -1;
      s.COLUMN = -1;
  }

  return s;
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
    // Suppose we want to find whether an element (el) is present in a matrix or not:
    int el = 610;

    // structure that will contain the coordinates of the searched element
    Struct coord;
    coord.ROW = -1;
    coord.COLUMN = -1;

    coord = matrix_search(a, el, N, M);
    if (coord.ROW!=-1) {printf("ROW: %d  COLUMN: %d\n", coord.ROW, coord.COLUMN);}

}
