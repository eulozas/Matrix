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
            matrix_t minor_matrix;
            exit_code = s21_create_matrix( A->rows - 1, A->columns - 1, &minor_matrix);
            //заполнить минорную матрицу
            //найти детерминант
            //записать в результ матрицу детерминант
            //у нас есть матрица миноров, умножить ее жлементы на -1^(i+j).


        }
    }

    return exit_code;
}