#include "s21_matrix.h"
#include <stdio.h>

int s21_eq_matrix(matrix_t *A, matrix_t *B){
    if(!A || !B){
        return 1;
    }

    int exit_code = SUCCESS;

    if(A->columns != B->columns || A->rows != B->rows){
        exit_code = FAILURE;
    }

    for(int i = 0; i < A->rows && exit_code; i++){
        for(int j = 0; j < A->columns && exit_code; j++){
            if(fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPS){
                exit_code = FAILURE;
            }
        }
    }
    
    return exit_code;
}