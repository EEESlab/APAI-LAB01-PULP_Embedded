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

// generic matrix-vector multiplication
int gemv(int N, int M, float * mat, float *vec, float * output_vec){

    for (int i=0; i<N; i++){
      for (int j=0; j<M; j++){
          // vectors are scrolled using a single index, while the matrix (which is still defined as a contiguous array) is scanned using two indeces
          *(output_vec+i) += *(mat+i*M+j)*(*(vec+j));
      }
    }

}


int main()
{
  int N = 5, M = 6;
  // we define the matrix as an array of size N*M
  float matrix[N*M];
  // we initialize the matrix as we wish, for example:
  for (int i=0; i<30; i++) { matrix[i] = i; }

  // the second vector operand is defined and initialized:
  float vector[M];
  for (int i=0; i<M; i++) { vector[i] = 10-i; }

  // we define also the output, and initialize it to 0s:
  float output[N];
  for (int i=0; i<N; i++) { output[i] = 0.0f; }

  // the matrix-vector product is performed and printed out:
  gemv(N, M, matrix, vector, output);
  for (int i=0; i<N; i++) { printf("%f \n", output[i]); }

}
