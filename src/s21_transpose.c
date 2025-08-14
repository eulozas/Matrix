#include "s21_matrix.h"
#include "s21_helpers.h"

int s21_transpose(matrix_t *A, matrix_t *result){
    if(!is_valid_matrix(A) || !result){
    return 1;
    }

    s21_create_matrix( A->columns, A->rows, result);
    for(int i = 0; i < result->rows; i++){
        for(int j = 0; j < result->columns; j++){
            result->matrix[i][j] = A->matrix[j][i];
        }
    }
    
    return 0;
}
