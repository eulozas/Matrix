#include "s21_helpers.h"
#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!is_valid_matrix(A) || !is_valid_matrix(B)) {
    return 0;
  }

  int exit_code = SUCCESS;

  if (A->columns != B->columns || A->rows != B->rows) {
    exit_code = FAILURE;
  }

  for (int i = 0; exit_code && i < A->rows; i++) {
    for (int j = 0; exit_code && j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPS) {
        exit_code = FAILURE;
      }
    }
  }

  return exit_code;
}