#include "s21_matrix.h"
#include "s21_helpers.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    if(!is_valid_matrix(A) || !is_valid_matrix(B) || !result){
        return 1;
    }

    int exit_code = 0;

    if(A->columns != B->columns || A->rows != B->rows){
        exit_code = 2;
    }

    if(!exit_code){
        s21_create_matrix(A->rows, A->columns, result);
        for(int i = 0; i < result->rows; i++){
            for(int j = 0; j < result->columns; j++){
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j]; 
            }
        }
    }
    return exit_code;
}