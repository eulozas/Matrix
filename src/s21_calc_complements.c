#include "s21_matrix.h"
#include "s21_helpers.h"

int s21_calc_complements(matrix_t *A, matrix_t *result){
    if(!is_valid_matrix(A) || !result){
        return 1;
    }

    int exit_code = 0;
    if(A->rows != A->columns){
        exit_code = 2;
    }

    if(!exit_code){
        s21_create_matrix( A->rows, A->columns, result);
        if(result->rows == 1 && result->columns == 1){
            result->matrix[0][0] = 1.0;
        }else{
            matrix_t minor_matrix;
            s21_create_matrix( A->rows - 1, A->columns - 1, &minor_matrix);
            s21_minor_matrix(A, &minor_matrix, result);  
            s21_mul_compl(result);
            s21_remove_matrix(&minor_matrix);
        }
    }
    return exit_code;
}