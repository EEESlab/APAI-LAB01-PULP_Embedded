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


// defines
#define N 5
#define M 6
#define mat_el (1.2f)  // matrix constant values
#define vec_el (2.0f)  // vector constant values

//utils
#define ABS(x)  ((x)>0?(x):(-x))
#define EPS     (0.00000001f)

// input variables
float matrix[N*M]; // the matrix as an array of size N*M
float vector[M];

// output variable
float output_vec[N];  // N*M x M*1 -> N*1


// generic matrix-vector multiplication
int gemv(int size_N, int size_M, float * mat_i, float *vec_i, float * vec_o){

    for (int i=0; i<size_N; i++){
      for (int j=0; j<size_M; j++){
          // mulitply accumulate operation
          vec_o[i] += mat_i[i*size_M+j] * vec_i[j];
          //*(vec_o+i) += *(mat_i+i*M+j)*(*(vec_i+j)); // try to uncomment this and comment the above line
      }
    }

}


int main()
{
  // Initialization of operands and reset the ouput
  for (int i=0; i<(N*M); i++) {
    matrix[i] = mat_el;
  }
  for (int i=0; i<M; i++) {
    vector[i] = vec_el;
  }
  for (int i=0; i<N; i++) {
    output_vec[i] = 0.0f;
  }

  // call the matrix-vector fucntion
  gemv(N, M, matrix, vector, output_vec);

  // print and check the results
  printf("The %d output elements are: ", N);
  for (int i=0; i<N; i++) {
    printf("%f, ", output_vec[i]);
  }
  printf("\n");

  // check here the results
  int correctness = 1;
  for (int i=0; i<N; i++) {
    if (ABS( output_vec[i]- (M*mat_el*vec_el)) > EPS )
    {
      correctness = 0;
      break;
    }
  }
  printf(correctness ? "RESULTS MATCHING\n" : "RESULTS NOT MATCHING\n");
}
