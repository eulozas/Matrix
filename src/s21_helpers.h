#ifndef S21_HELPERS_H
#define S21_HELPERS_H

#include <math.h>
#include <stdlib.h>

#include "s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-6

int is_valid_matrix(const matrix_t *A);
void s21_copy_matrix(matrix_t *A, matrix_t *B);
void s21_init_matrix(matrix_t *A, const double *arr);
void s21_mult_number_str_matrix(matrix_t *A, int strA, double number,
                                matrix_t *B, int strB);
void s21_sub_matrix_str(matrix_t *A, int strA, matrix_t *B, int strB,
                        matrix_t *result, int strRes);
int zero_row_col_check(const matrix_t *A);
void s21_change_rows(int rows1, int rows2, matrix_t *A);
void s21_mul_neg1(int rows, matrix_t *A);
void make_zero_element(int i, int j, matrix_t *A, matrix_t *vector_str);
void transform_to_echelon_form(matrix_t *A);
void s21_init_minor_matrix(int m, int n, matrix_t *A, matrix_t *minor_matrix);
void s21_mul_compl(matrix_t *A);
void s21_minor_matrix(matrix_t *A, matrix_t *minor, matrix_t *result);
void s21_mul_det(matrix_t *A, double det, matrix_t *res);

#endif