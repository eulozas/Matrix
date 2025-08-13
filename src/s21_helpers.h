#ifndef S21_HELPERS_H
#define S21_HELPERS_H
#include "s21_matrix.h"

int s21_is_zero_matrix(matrix_t *A);
void s21_copy_matrix(matrix_t *A, matrix_t *B);
void s21_init_matrix(matrix_t *A, double *arr);
void s21_print_matrix(matrix_t *A);
void s21_mult_number_str_matrix(matrix_t *A, int strA, double number, matrix_t *B, int strB);
void s21_sub_matrix_str(matrix_t *A, int strA, matrix_t *B, int strB, matrix_t *result, int strRes);
int zero_row_col_check(matrix_t *A);
void s21_change_rows(int rows1, int rows2, matrix_t *A);
void s21_mul_neg1(int rows, matrix_t *A);
void s21_init_minor_matrix(int m, int n,  matrix_t *A,  matrix_t *minor_matrix);
void s21_mul_compl(matrix_t *A);
void s21_clean_matrix(matrix_t *A);

#endif