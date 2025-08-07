#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
      if(!A || !B || !result){
        return 1;
    }

    int exit_code = 0;

    if(A->columns != B->rows || A->rows != result->rows || B->columns != result->columns){
        exit_code = 2;
    }

    for(int i = 0; i < A->rows && !exit_code; i++){
        for(int j = 0; j < A->columns; j++){
            result->matrix[i][j] = A->matrix[i][j];
        }
    }

    return exit_code;
}