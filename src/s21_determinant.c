#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result){
    if(!A || !result){
    return 1;
    }

    int exit_code = 0;
    if(A->rows != A->columns){
        exit_code = 2;
    }

    if(!exit_code){
        if(A->rows == 1 && A->columns == 1){
            *result = A->matrix[0][0];
            //еще если хоть один ряд\строка заполнены нулями, то определитель ноль, написать ф-цию проверки
        }else{
            matrix_t B;
            exit_code = s21_create_matrix(A->rows, A->columns, &B);
            if(!exit_code){
                s21_copy_matrix(A, &B);
                double mul = 0;
                matrix_t vector_str;
                matrix_t vector_str_result;
                for(int i = 1; i < B.columns && !exit_code; i++){
                    for(int j = 0; j!=i && !exit_code; j++){
                        if(B.matrix[i][j] != 0){
                            mul = B.matrix[i][j]/B.matrix[i-1][j];
                            exit_code = s21_mult_number(&B.matrix[i], mul, &vector_str.matrix[0]);
                            if(!exit_code) exit_code = s21_sub_matrix(&B.matrix[i], &vector_str.matrix[0], &vector_str_result);
                            if(!exit_code) s21_copy_matrix(&B.matrix[i], &vector_str_result);
                            s21_remove_matrix(&vector_str);
                            s21_remove_matrix(&vector_str_result);
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
    }
    
    return exit_code;
}