#include "s21_helpers.h"
#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!is_valid_matrix(A) || !is_valid_matrix(B) || !result) {
    return 1;
  }

  int exit_code = 0;

  if (A->columns != B->rows) exit_code = 2;

  if (!exit_code) s21_create_matrix(A->rows, B->columns, result);

  for (int i = 0; !exit_code && i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = 0;
      int k = 0;
      while (k < A->columns) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        k++;
      }
    }
  }

  return exit_code;
}