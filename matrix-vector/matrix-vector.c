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


int gemv(int N, int M, float * mat, float *vec, float * output_vec){

    for (int i=0; i<N; i++){
      for (int j=0; j<M; j++){
          *(output_vec+i) += *(mat+i*M+j)*(*(vec+j));
      }
    }

}


int main()
{
  int N = 5, M = 6;
  float matrix[N*M];
  for (int i=0; i<30; i++) { matrix[i] = i; }

  float vector[M];
  for (int i=0; i<M; i++) { vector[i] = 10-i; }

  float output[N];
  for (int i=0; i<N; i++) { output[i] = 0.0f; }

  gemv(N, M, matrix, vector, output);
  for (int i=0; i<N; i++) { printf("%f \n", output[i]); }

}
