#include "s21_matrix.h"
#include "s21_helpers.h"

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
            matrix_t minor_matrix;
            exit_code = s21_create_matrix( A->rows - 1, A->columns - 1, &minor_matrix);
            double determinant;

            for(int i = 0; i < A->rows; i++){
                for(int j = 0; j < A->columns; j++){
                    s21_init_minor_matrix(i, j, A, &minor_matrix);
                    s21_determinant(&minor_matrix, &determinant);
                    result->matrix[i][j] = determinant;
                }
            }
            s21_mul_compl(result);
            s21_remove_matrix(&minor_matrix);
        }
    }

    return exit_code;
}