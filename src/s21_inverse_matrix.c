#include "s21_matrix.h"
#include "s21_helpers.h"
#include <stdio.h>

int s21_inverse_matrix(matrix_t *A, matrix_t *result){
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
        result->matrix[0][0] = 1.0/A->matrix[0][0];
        }else{
            double determinant;
            s21_determinant(A, &determinant);
            if(determinant!=0.0){
                matrix_t calc_matrix;
                s21_calc_complements(A, &calc_matrix);
                matrix_t transp_matrix;
                s21_transpose(&calc_matrix, &transp_matrix);
                s21_remove_matrix(&calc_matrix);
                s21_mult_number(&transp_matrix, 1.0/determinant, result);
                s21_remove_matrix(&transp_matrix);
            }else{
                exit_code = 2;
            }
        }
    }
    return exit_code;
}