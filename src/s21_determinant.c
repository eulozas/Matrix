#include "s21_matrix.h"
#include "s21_helpers.h"
#include <stdio.h>

int s21_determinant(matrix_t *A, double *result){
    if(!is_valid_matrix(A) || !result){
        return 1;
    }

    int exit_code = 0;
    if(A->rows != A->columns){
        exit_code = 2;
    }

    if(!exit_code){
        if(A->rows == 1 && A->columns == 1){
            *result = A->matrix[0][0];
        }else if(zero_row_col_check(A)){
            *result = 0.0;
        }else{
            matrix_t B;
            s21_create_matrix(A->rows, A->columns, &B);
            s21_copy_matrix(A, &B);
            double mul = 0;
            matrix_t vector_str;
            for(int i = 1; i < B.columns; i++){
                for(int j = 0; j!=i; j++){
                    s21_create_matrix(1, B.columns, &vector_str);
                    if(B.matrix[i][j] != 0){
                        if(B.matrix[j][j] == 0){
                            s21_change_rows(i, j, &B);
                            s21_mul_neg1(i, &B);
                        }else{
                            mul = B.matrix[i][j]/B.matrix[j][j];
                            s21_mult_number_str_matrix(&B, j, mul, &vector_str, 0);
                            s21_sub_matrix_str(&B, i, &vector_str, 0, &B, i);
                            s21_remove_matrix(&vector_str);
                            }
                        }
                    }
                }
            *result = B.matrix[0][0];
            for(int i = 1; i < B.rows; i++){
                *result *= B.matrix[i][i];
            }
            s21_remove_matrix(&B); 
        }
    }

    return exit_code;
}