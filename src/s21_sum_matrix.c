#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    if(!A || !B || !result){
        return 1;
    }

    int exit_code = 0;

    if(A->columns != B->columns || A->rows != B->rows || A->rows != result->rows || A->columns != result->columns){
        exit_code = 2;
    }

    if(s21_is_zero_matrix(A) && !exit_code){
        for(int i = 0; i < B->rows; i++){
            for(int j = 0; j < B->columns; j++){
                result->matrix[i][j] = B->matrix[i][j];
            }
        }
    } else if(s21_is_zero_matrix(B) && !exit_code){
        for(int i = 0; i < A->rows; i++){
            for(int j = 0; j < A->columns; j++){
                result->matrix[i][j] = A->matrix[i][j];
            }
        }
    } else {
        for(int i = 0; i < A->rows && !exit_code; i++){
            for(int j = 0; j < A->columns; j++){
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
    }

    return exit_code;
}