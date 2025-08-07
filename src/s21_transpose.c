#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result){
    if(!A || !result){
    return 1;
    }

    int exit_code = s21_create_matrix( A->columns, A->rows, result);
    if(!exit_code){
        for(int i = 0; i < result->rows; i++){
            for(int j = 0; j < result->columns; j++){
                result->matrix[i][j] = A->matrix[j][i];
            }
        }
    }
    return exit_code;
}
