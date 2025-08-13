#include "s21_helpers.h"
#include <stdio.h>

int s21_is_zero_matrix(matrix_t *A){

    int exit_code = 1;
    for(int i = 0; i < A->rows && exit_code; i++){
        for(int j = 0; j < A->columns && exit_code; j++){
            if(fabs(A->matrix[i][j]) > EPS){
                exit_code = 0;
            }
        }
    }

    return exit_code;
}


void s21_copy_matrix(matrix_t *A, matrix_t *B){
    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < A->columns; j++){
            B->matrix[i][j] = A->matrix[i][j];
        }
    }
}

void s21_init_matrix(matrix_t *A, double* arr){
    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < A->columns; j++){
            A->matrix[i][j] = arr[i*A->rows + j];
        }
    }
}

void s21_print_matrix(matrix_t *A){
    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < A->columns; j++){
           printf("%.2f ", A->matrix[i][j]);
        }
         printf("\n");
    }
}

void s21_mult_number_str_matrix(matrix_t *A, int strA, double number, matrix_t *B, int strB){
    for(int i = 0; i < A->columns; i++){
        B->matrix[strB][i] = A->matrix[strA][i] * number;
    }
}

void s21_sub_matrix_str(matrix_t *A, int strA, matrix_t *B, int strB, matrix_t *result, int strRes){
    for(int i = 0; i < A->columns; i++){
        result->matrix[strRes][i] = A->matrix[strA][i] - B->matrix[strB][i];
    }
}

int zero_row_col_check(matrix_t *A){
    int exit_code = 0;

    for(int i = 0; i < A->rows && !exit_code; i++){
        int count_zero_in_row = 0;
        for(int j = 0; j < A->columns; j++){
            if(fabs(A->matrix[i][j]) <= EPS){
                count_zero_in_row++;
            }
        }
        if(count_zero_in_row == A->columns){
            exit_code = 1;
        }
    }

    for(int i = 0; i < A->columns && !exit_code; i++){
        int count_zero_in_column = 0;
        for(int j = 0; j < A->rows; j++){
            if(fabs(A->matrix[j][i]) <= EPS){
                count_zero_in_column++;
            }
        }
        if(count_zero_in_column == A->rows){
            exit_code = 1;
        }
    }

    return exit_code;
}

void s21_change_rows(int rows1, int rows2, matrix_t *A){
    double tmp;
    for(int j = 0; j < A->columns; j++){
        tmp = A->matrix[rows1][j];
        A->matrix[rows1][j] = A->matrix[rows2][j];
        A->matrix[rows2][j] = tmp;
    }
}

void s21_mul_neg1(int rows, matrix_t *A){
    for(int j = 0; j < A->columns; j++){
         A->matrix[rows][j] *= -1;
    }
}

void s21_init_minor_matrix(int m, int n,  matrix_t *A,  matrix_t *minor_matrix){
    int row = 0;
    for(int i = 0; i < A->rows; i++){
        int col = 0;
        for(int j = 0; j < A->columns && i!=m; j++){
            if(j!=n){
                minor_matrix->matrix[row][col] = A->matrix[i][j]; 
                col++;
            }
        }
        if(i!=m) row++;
    }
}

void s21_mul_compl(matrix_t *A){
    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < A->columns; j++){
            A->matrix[i][j]*=pow(-1,i+j);
        }
    }
}

void s21_clean_matrix(matrix_t *A){
    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < A->columns; j++){
            A->matrix[i][j] = 0.0;
        }
    }
    A->rows = 0;
    A->columns = 0;
}


int main(){
    matrix_t A;
    //matrix_t B;
    matrix_t res;
    double arr1[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
    //double arr2[] = {1.1,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
   double result;
    // double n = 2.0;

    s21_create_matrix(3, 3, &A);
    //s21_create_matrix(3, 3, &res);
    //s21_create_matrix(3, 3, &B);
    s21_init_matrix(&A, arr1);
   // s21_init_matrix(&B, arr2);
    s21_print_matrix(&A);
    printf("\n");
    // s21_print_matrix(&B);

    s21_determinant(&A, &result);
    printf("%f\n", result);

    //s21_calc_complements(&A, &res);
    //s21_print_matrix(&res);
    //printf("\n");

    //matrix_t res1;

    //s21_inverse_matrix(&A, &res1);
    //s21_print_matrix(&res1);

    return 0;
}