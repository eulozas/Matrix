#include "s21_matrix.h"
#include "s21_helpers.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result){
    if(!A || !result){
    return 1;
    }

    int exit_code = 0;
    if(A->rows != A->columns){
        exit_code = 2;
    }

    if(!exit_code){
        exit_code = s21_create_matrix( A->rows, A->columns, result);
        if(result->rows == 1 && result->columns == 1 && !exit_code){
        result->matrix[0][0] = 1.0/A->matrix[0][0];
        }else{
            double determinant;
            s21_determinant(A, &determinant);
            if(determinant!=0){
                matrix_t transp_matrix;
                exit_code = s21_calc_complements(A, result);
                if(!exit_code) exit_code = s21_transpose(result, &transp_matrix);
                s21_clean_matrix(result);
                if(!exit_code) exit_code = s21_mult_number(&transp_matrix, determinant, result);
                s21_remove_matrix(&transp_matrix);
            }
        }
    }
    return exit_code;
}