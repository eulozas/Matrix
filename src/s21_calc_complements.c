#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result){
    if(!A || !result){
    return 1;
    }

    int exit_code = 0;
    if(A->rows != A->columns){
        exit_code = 2;
    }

    if(!exit_code) exit_code = s21_create_matrix( A->rows, A->columns, result);
    if(!exit_code){
        if(result->rows == 1 && result->columns == 1){
        result->matrix[0][0] = A->matrix[0][0];
        }else{


        }
    }

    return exit_code;
}