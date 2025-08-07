#include "s21_helpers.h"

s21_is_zero_matrix(matrix_t *A){

    int exit_code = 1;
    for(int i = 0; i < A->rows && exit_code; i++){
        for(int j = 0; j < A->columns && exit_code; j++){
            if(A->matrix[i][j] != 0){
                exit_code = 0;
            }
        }
    }

    return exit_code;
}