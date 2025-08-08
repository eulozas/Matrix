#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    if(!A || !B || !result){
        return 1;
    }

    int exit_code = 0;

    if(A->columns != B->columns || A->rows != B->rows){
        exit_code = 2;
    }
    
    if(!exit_code){
    matrix_t neg_B;
    if(!exit_code) exit_code = s21_mult_number(B, -1.0, &neg_B);
    if(!exit_code) exit_code = s21_sum_matrix(A, &neg_B, result);
    s21_remove_matrix(&neg_B);
    }

    return exit_code;
}