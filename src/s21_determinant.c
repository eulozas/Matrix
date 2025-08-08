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
        }else{
            matrix_t B;
            exit_code = s21_create_matrix(A->rows, A->columns, &B);
            if(!exit_code) exit_code = s21_mult_number(A, 1, &B);//так копировала матрицу, может вынести в отдельную ф-цию
            if(!exit_code){
                int zero_count = 3; //написать ф-цию для подсчета сколько нам нужно нулей для получения треуг матрицы
                double mul = 0;
                matrix_t vector_str;
                int k1 = 0;//коэффициент для правильного подсчета индексов вычитаемой строки
                int k2 = 1;//коэффициент для правильного подсчета индексов уменьшаемой строки
                exit_code = s21_create_matrix(1, B.columns, &vector_str);
                for(int i = 0; i < zero_count && !exit_code; i++){
                    mul = find_mul_num(); //функция, которая определит на какое число нужно умножать вычитаемую строку
                    exit_code = s21_mult_number(B.matrix[i+k1], mul, &vector_str);
                    if(!exit_code) exit_code = s21_sub_matrix(B.matrix[i+k2], &vector_str, B.matrix[i+k2]);
                    k1=k1_func(); //функции для правильного изменения коэффициента
                    k2=k2_func();
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