#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result){
    if(!A || !result){
        return 1;
    }

    int exit_code = s21_create_matrix(A->rows, A->columns , result);

    for(int i = 0; i < A->rows && !exit_code; i++){
        for(int j = 0; j < A->columns; j++){
            result->matrix[i][j] = A->matrix[i][j] * number;
        }
    }

    return exit_code;
}