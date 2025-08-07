#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result){
    if(!A || !result || isnan(number) || isinf(number)){ //нужно ли на НаН и Инф сверять или матрица этими значениями мб заполнена?
        return 1;
    }

    int exit_code = 0;
    if (A->rows != result->rows || A->columns != result->columns) {
    exit_code = 2;
    }

    for(int i = 0; i < A->rows && !exit_code; i++){
        for(int j = 0; j < A->columns; j++){
            result->matrix[i][j] = A->matrix[i][j] * number;
        }
    }

    return exit_code;
}